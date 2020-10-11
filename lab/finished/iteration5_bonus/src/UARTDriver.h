#ifndef _UARTDRIVER_H
#define _UARTDRIVER_H

#define UART_INTERNAL_FIFO_LEN    (16)

typedef enum _UART_PORT_T
{
    UART_PORT1 = 0,
    UART_PORT2,
    UART_PORT3,

    UART_NUM_PORTS
} UART_PORT_T;

void UARTDriver_Init(void);
STATUS_T UARTDriver_Enable(UART_PORT_T port);
STATUS_T UARTDriver_Disable(UART_PORT_T port);
STATUS_T UARTDriver_PutChar(UART_PORT_T port, char Val);
char UARTDriver_GetChar(UART_PORT_T port);

BOOL UARTDriver_Connected(UART_PORT_T port);
BOOL UARTDriver_OkayToRead(UART_PORT_T port);
BOOL UARTDriver_OkayToWrite(UART_PORT_T port);

#endif // _USARTDRIVER_H
