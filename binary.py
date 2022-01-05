import os
import binascii
import struct

misc = open("ogo.png","rb").read()
print(misc[12:16])
print( misc[20:29])
for i in range(2000):
  for j in range(2000):
    data = misc[12:16] + struct.pack('>i',i) + struct.pack('>i',j)+ misc[24:29]
    crc32 = binascii.crc32(data) & 0xffffffff
    #print(data)
    #print(crc32)
    if crc32 == 0x01897642: # 0x01897642
      print(struct.pack('>i',i)+ struct.pack('>i',j))