import os
import binascii
import struct

misc = open("misc4.png","rb").read()
print(misc[12:16]) # 'IHDR'
print(misc[20:29])
for i in range(2000):
  for j in range(2000):
    data = misc[12:16] + struct.pack('>i',i) + struct.pack('>i',j)+ misc[24:29]
    crc32 = binascii.crc32(data) & 0xffffffff
    if crc32 == 0x932f8a6b: # CRC32
      print(struct.pack('>i',i)+ struct.pack('>i',j))
