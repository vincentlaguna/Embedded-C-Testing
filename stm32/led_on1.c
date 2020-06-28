//#include <stdio.h>
#include <stdint.h>

int main(void)
{
  uint32_t *pClkCtrlReg =   (uint32_t*)0x40023830;
  uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
  uint32_t *pPortDOutReg =  (uint32_t*)0x40020C14;
  // 1. Enable the clock for GPIOD peripheral in the AHB1ENR
  uint32_t temp = *pClkCtrlReg; // Read operation
  temp = temp | 0x08; // Modify
  *pClkCtrlReg = temp; // Write back
  
  //*pClkCtrlReg = *pClkCtrlReg | 0x08; // Same as previous three lines
  //*pClkCtrlReg |= 0x08; // Same as previous line
  // 2. Configure the mode of the IO pin as output
  // a. Clear the 24th bit and 25th bit positions (CLEAR)
  *pPortDModeReg &= 0xFCFFFFFF;
  // b. Make the 24th bit position as 1 (SET)
  *pPortDModeReg |= 0x01000000;
  // 3. Set 12th bit of the output data register to make I/O pin-12 HIGH
  *pPortDOutReg |= 0x1000;
  
  while(1);
}