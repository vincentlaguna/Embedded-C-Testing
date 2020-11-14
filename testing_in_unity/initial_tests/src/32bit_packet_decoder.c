/*******************************************************************************
*                                                                              *
*                           32-bit Packet Decoder                              *
* Format:                                                                      *
*                                                                              *
* <ADDR_MODE>|<SHORT_ADDR>|<LONG_ADDR>|<SENSOR>|<BAT>|<PAYLOAD>|<STATUS>|<CRC> *
*      1            2           8         3       3       12       1       2   *
*                                                                              *
********************************************************************************/
// Second working iteration optimized using bit-field
// Refactor 201113-1920
#include <stdio.h>
#include <stdint.h>

typedef struct
{
  uint32_t crc        :2;
  uint32_t status     :1;
  uint32_t payload    :12;
  uint32_t bat        :3;
  uint32_t sensor     :3;
  uint32_t longAddr   :8;
  uint32_t shortAddr  :2;
  uint32_t addrMode   :1;
}Packet_t;

uint32_t _32bit_packet_decoder(uint32_t packetValue)
{
//   uint32_t packetValue;
//   printf("Enter 32-bit Packet Value: ");
//   scanf("%x", &packetValue);
  
  Packet_t packet;
  
  packet.crc        = (uint8_t)(packetValue & 0x3);
  packet.status     = (uint8_t)((packetValue >> 2) & 0x1);
  packet.payload    = (uint16_t)((packetValue >> 3) & 0xFFF);
  packet.bat        = (uint8_t)((packetValue >> 15) & 0x7); 
  packet.sensor     = (uint8_t)((packetValue >> 18) & 07);
  packet.longAddr   = (uint8_t)((packetValue >> 21) & 0xFF);
  packet.shortAddr  = (uint8_t)((packetValue >> 29) & 0x3);
  packet.addrMode   = (uint8_t)((packetValue >> 31) & 0x3);
  
//   printf("crc       : [ %#x ]\n", packet.crc);
//   printf("status    : [ %#x ]\n", packet.status);
//   printf("payload   : [ %#x ]\n", packet.payload);
//   printf("bat       : [ %#x ]\n", packet.bat);
//   printf("sensor    : [ %#x ]\n", packet.sensor);
//   printf("longAddr  : [ %#x ]\n", packet.longAddr);
//   printf("shortAddr : [ %#x ]\n", packet.shortAddr);
//   printf("addrMode  : [ %#x ]\n", packet.addrMode);
  
//   printf("Size of structure is -> %ld\n", sizeof(Packet_t));
  
//   while(getchar() != '\n')
//   getchar();
  
  return packet.crc;
}
