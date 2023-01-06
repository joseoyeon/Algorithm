import struct
import hexdump
from ctypes import *

MAGIC_ID = b'\xD0\xCF\x11\xE0\xA1\xB1\x1A\xE1'  # D0CF11E0 A1B11AE1
SECTORSIZE = 0x200
MINISECTORSIZE = 0x40
DIRECTORYENTRYSIZE = 0x80
MINISTREAMCUTOFFSIZE = int()

STORAGE = 0x1
STREAM = 0x2
ROOT = 0x5

MAXFATENTRY = 109
MAXREGSID = 0xFFFFFFFA
NOSTREAM = 0xFFFFFFFF
MAXREGSECT = 0xFFFFFFFA  # 일반적인 섹터의 끝번호 + 1
ENDOFCHAIN = 0xFFFFFFFE  # 섹터 체인의 끝
FREESECT = 0xFFFFFFFF  # 미할당섹터
FATSECT = 0xFFFFFFFD  # FAT Sector
DIFSECT = 0xFFFFFFFC  # DIFAT sector


class CompoundFileHeader(LittleEndianStructure):

    MAXFATENTRYNUM = 109

    _fields_ = [
        ('HeaderSignature', c_ubyte * 8),
        ('HeaderCLSID', c_ubyte * 16),
        ('MinorVersion', c_ushort),  # SHOULD be 0x003E if Major is 0x0003 or 0x0004
        ('MajorVersion', c_ushort),
        ('ByteOrder', c_ushort),  # MUST be set to 0xFFFE
        ('SectorShift', c_ushort),  # MUST be set to 0x0009, or 0x000c, depending of MajorVersion
        ('MiniSectorShift', c_ushort),
        ('Reserved', c_ubyte * 6),  # MUST 0
        ('NumberOfDirectorySectors', c_uint32),
        ('NumberOfFATSectors', c_uint32),
        ('FirstDirectorySectorLocation', c_uint32),
        ('TransactionSignatureNumber', c_uint32),
        ('MiniStreamCutoffSize', c_uint32),
        ('FirstMiniFATSectorLocation', c_uint32),
        ('NumberOfMiniFATSectors', c_uint32),
        ('FirstDIFATSectorLocation', c_uint32),
        ('NumberOfDIFATSectors', c_uint32),
        ('DIFAT', c_uint32 * MAXFATENTRY)
    ]
    pattern = '< 8s 16s H H H H H 6s I I I I I I I I I ' + str(MAXFATENTRY) + 'I'

    def make(self, bytes):
        fit = min(len(bytes), sizeof(self))
        memmove(addressof(self), bytes, fit)


class DirectoryEntry(LittleEndianStructure):
    """
    | offset | Field Name                  | Example                                               |
    |--------|-----------------------------|-------------------------------------------------------|
    | 0x0400 | Directory Entry Name        | Root Entry (section 2.6.2)                            |
    | 0x0440 | Directory Entry Name Length | 0x16 (22 bytes)                                       |
    | 0x0442 | Object Type                 | 0x05 (root storage)                                   |
    | 0x0443 | Color Flag                  | 0x01 (black)                                          |
    | 0x0444 | Left Sibling ID             | 0xFFFFFFFF (none)                                     |
    | 0x0448 | Right Sibling ID            | 0xFFFFFFFF (none)                                     |
    | 0x044C | Child ID                    | 0x00000001 (Stream ID 1: "Storage 1" (section 2.6.3)) |
    | 0x0450 | CLSID                       | 0x11CEC15456616700 0xAA005385 0x5BF9A100              |
    | 0x0460 | State Flags                 | 0x00000000                                            |
    | 0x0464 | Creation Time               | 0x0000000000000000                                    |
    | 0x046C | Modification Time           | 0x0000000000000000                                    |
    | 0x0474 | Starting Sector Location    | 0x00000003 (sector #3 for mini Stream)                |
    | 0x0478 | Stream Size                 | 0x0000000000000240 (576 bytes)                        |
    """
    _pack_ = 1
    _fields_ = [
        ('DirectoryEntryName', c_ubyte * 0x40),
        ('DirectoryEntryNameLength', c_short),
        ('ObjectType', c_ubyte),
        ('ColorFlag', c_ubyte),
        ('LeftSiblingID', c_uint32),
        ('RightSiblingID', c_uint32),
        ('ChildID', c_uint32),
        ('CLSID', c_ubyte * 0x10),
        ('StateFlags', c_uint32),
        ('CreationTime', c_uint64),
        ('ModificationTime', c_uint64),
        ('StartingSectorLocation', c_uint32),
        ('StreamSize', c_uint64)
    ]

    def make(self, bytes):
        fit = min(len(bytes), sizeof(self))
        memmove(addressof(self), bytes, fit)


class OleParser:

    def __init__(self, fileName):
        """
        여기서 CFB 파일의 필수 구성 요소들을 설정한다.
        :param fileName:  OLE 파일명
        """
        self.oleFile = open(fileName, 'rb')

        self.compoundFileHeader = CompoundFileHeader()
        self.FATarray = list()
        self.FATstream = None  # FATarray 가 참조하는 스트림은 OLE 파일 자체
        self.miniFATarray = list()
        self.miniFATstream = list()  # miniFATarray 가 참조하는 스트림은 Root Directory Entry (Root Entry)의 스트림에 보관
        self.directoryEntryArray = list()

        '''
        CompoundFileHeader 를 설정한다
        '''
        buf = self.readSector(-1)
        self.compoundFileHeader.make(buf)
        global MINISTREAMCUTOFFSIZE
        MINISTREAMCUTOFFSIZE = self.compoundFileHeader.MiniStreamCutoffSize

        '''
        FAT Array 를 설정한다 (BBAT)
        '''
        FATsectors = list()
        for i in range(0, MAXFATENTRY):
            if (self.compoundFileHeader.DIFAT[i] == FREESECT) or \
                    (self.compoundFileHeader.NumberOfFATSectors < i):
                break
            FATsectors.append(self.compoundFileHeader.DIFAT[i])

        # DIFAT Array 가 존재한다면
        buf = b''
        DIFATsector = self.compoundFileHeader.FirstDIFATSectorLocation
        for i in range(0, self.compoundFileHeader.NumberOfDIFATSectors):
            # 해당 섹터를 읽고
            buf = self.readSector(DIFATsector)
            # 인덱스로 4byte 씩 접근할 수 있게 가공한다
            DIFAT = self.littleEndianBinaryToList(buf)
            # 다음섹터 위치를 표시하는 마지막 인덱스를 취하고
            DIFATsector = DIFAT[-1]
            # FATsectors 에는 추가하지 않는다
            FATsectors += DIFAT[:-1]

        buf = b''
        for FAT in FATsectors:
            buf += self.readSector(FAT)
        # 인덱스로 4byte 씩 접근할 수 있게 가공하면 최종적으로 FAT Array (BBAT)가 완성된다
        self.FATarray = self.littleEndianBinaryToList(buf)

        '''
        miniFAT Array 를 설정한다 (SBAT)
        '''
        startSector = self.compoundFileHeader.FirstMiniFATSectorLocation
        if self.compoundFileHeader.NumberOfMiniFATSectors > 1:  # FATarray 를 참고해 여러 섹터를 가져옴
            buf = self.readStreamFromFATarray(startSector)
        else:  # 파일에서 해당 섹터만 가져옴
            buf = self.readSector(startSector)
        # 인덱스로 4byte 씩 접근할 수 있게 배열로 저장한다
        self.miniFATarray = self.littleEndianBinaryToList(buf)

        '''
        DirectoryEntry Array 를 설정한다 (Properties)
        '''
        buf = self.readStreamFromFATarray(self.compoundFileHeader.FirstDirectorySectorLocation)
        # 인덱스로 DIRECTORY_ENTRY_SIZE 로 접근 할 수 있게 리스트로 가공해서 저장
        for i in range(0, len(buf), DIRECTORYENTRYSIZE):
            directoryEntry = DirectoryEntry()
            directoryEntry.make(buf[i:i+DIRECTORYENTRYSIZE])
            self.directoryEntryArray.append(directoryEntry)

        '''
        DirectoryEntry_root 가 있으니 miniFAT stream 을 설정한다 (Small Data Block)
        '''
        self.miniFATstream = self.readStreamFromFATarray(self.directoryEntryArray[0].StartingSectorLocation)

        '''
        파싱이 끝난 CFB 파일의 스토리지, 스트림으로 원하는 작업을 수행한다.
        '''

    def readSector(self, sectorNum):
        """
        섹터 번호에 해당하는 값을 파일에서 읽어온다
        :param sectorNum:
        :return:
        """
        offset = (sectorNum + 1) * SECTORSIZE
        self.oleFile.seek(offset)
        buf = self.oleFile.read(SECTORSIZE)
        return buf

    def readMiniSector(self, sectorNum):
        """
        미니 섹터 번호에 해당하는 값을 miniFATstream 에서 읽어온다
        파일 자체인 FAT stream 과 달리
        miniFAT stream 을 가져올땐 헤더가 없어,
        offset 을 구하는 공식이 다르다
        :param sectorNum:
        :return:
        """
        offset = sectorNum * MINISECTORSIZE
        buf = self.miniFATstream[offset:offset+MINISECTORSIZE]
        return buf

    def readStreamFromMiniFATarray(self, startSector):
        """
        miniFAT array 체인에 따라 해당하는 miniFAT 스트림 조각 들을 하나로 리턴한다
        :param startSector: 시작 엔트리
        :return:
        """
        buf = b''
        sectorNum = startSector
        while sectorNum not in (ENDOFCHAIN, NOSTREAM) and sectorNum < MAXREGSID:
            buf = buf + self.readMiniSector(sectorNum)
            sectorNum = self.miniFATarray[sectorNum]
        return buf

    def readStreamFromFATarray(self, startSector):
        """
        FAT array 체인에 따라 해당하는 스트림 조각 들을 하나로 리턴한다
        :param startSector: 시작엔트리
        :return: b''
        """
        buf = b''
        sectorNum = startSector
        while sectorNum not in (ENDOFCHAIN, FREESECT):
            buf = buf + self.readSector(sectorNum)
            sectorNum = self.FATarray[sectorNum]
        return buf

    def littleEndianBinaryToList(self, binaryData, dataSize=4):
        """
        리틀 엔디언으로 저장된 데이터를 dataSize 단위로 읽어들여 리스트로 반환한다
        :param binaryData: 변환할 바이너리데이터
        :param dataSize: 리스트로 자를 단위
        :return: list()
        """
        if len(binaryData) % dataSize != 0:
            return None
        return [struct.unpack('<I', binaryData[i:i + 4])[0] for i in range(0, len(binaryData), dataSize)]

    def displayDirectoryEntryStream(self, directoryEntryId):

        buf = b''
        directoryEntry = self.directoryEntryArray[directoryEntryId]

        if directoryEntry.ObjectType == STORAGE:
            return hexdump.hexdump(buf)

        streamSize = directoryEntry.StreamSize
        startSector = directoryEntry.StartingSectorLocation

        if streamSize < MINISTREAMCUTOFFSIZE and directoryEntry.ObjectType != ROOT:
            buf = self.readStreamFromMiniFATarray(startSector)
        else:
            buf = self.readStreamFromFATarray(startSector)

        print(bytes(directoryEntry.DirectoryEntryName).decode('utf16'))
        return hexdump.hexdump(buf)

    def displayDirectoryEntryNames(self, directoryEntryId=0, depth=0):
        directoryEntry = self.directoryEntryArray[directoryEntryId]
        tab = '    ' * depth
        print('[%02d]' % directoryEntryId + tab + bytes(directoryEntry.DirectoryEntryName).decode('utf16'))
        if directoryEntry.ChildID != NOSTREAM:
            depth += 1
            self.displayDirectoryEntryNames(directoryEntry.ChildID, depth)
        if directoryEntry.LeftSiblingID != NOSTREAM:
            self.displayDirectoryEntryNames(directoryEntry.LeftSiblingID, depth)
        if directoryEntry.RightSiblingID != NOSTREAM:
            self.displayDirectoryEntryNames(directoryEntry.RightSiblingID, depth)


def showValue(structure):
    buf = b''
    for field_name, field_type in structure._fields_:
        print('%s : ' % field_name, getattr(structure, field_name))
    return buf


def main():
    # 파일을 열고 작업을 시작하자
    ole = OleParser('영업실적_기밀')
    ole.displayDirectoryEntryNames()
    ole.displayDirectoryEntryStream(5)

if __name__ == '__main__':
    main()