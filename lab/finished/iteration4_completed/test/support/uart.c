
// UART0 address for Stellaris LM3S6965 eval board
// (Cortex M3 machine emulation option for Qemu)
volatile unsigned int * const UART0DR = (unsigned int *)0x4000c000;

// Qemu's simple model of a UART includes no buffers, control registers, etc.
void print_uart0(const char s)
{
  *UART0DR = (unsigned int)s; /* Transmit char */
}
