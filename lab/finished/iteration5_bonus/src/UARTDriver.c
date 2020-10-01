
#include "Core.h"
#include "Params.h"
#include "UARTDriver.h"
#include "serial_api.h"


static BOOL initialized[UART_NUM_PORTS];
static serial_t serial[UART_NUM_PORTS];
static uint16_t baudrate[UART_NUM_PORTS];

void BaudRateUpdate(UART_PORT_T port)
{
    if (initialized[port])
    {
        serial_baud(&serial[port], baudrate[port]);
        serial_clear(&serial[port]);
    }
}

void BaudRateUpdateCom1(void) { BaudRateUpdate(UART_PORT1); }
void BaudRateUpdateCom2(void) { BaudRateUpdate(UART_PORT2); }
void BaudRateUpdateCom3(void) { BaudRateUpdate(UART_PORT3); }

void UARTDriver_Init(void)
{
    int i;

    for (i=0; i < UART_NUM_PORTS; i++)
    {
        initialized[i] = FALSE;
    }

    Param_RegisterU16WithCallback(PARAM_COM1_BAUD, 300, 57600, 9600, &baudrate[0], BaudRateUpdateCom1);
    Param_RegisterU16WithCallback(PARAM_COM2_BAUD, 300, 57600, 9600, &baudrate[1], BaudRateUpdateCom2);
    Param_RegisterU16WithCallback(PARAM_COM3_BAUD, 300, 57600, 9600, &baudrate[2], BaudRateUpdateCom3);
}

STATUS_T UARTDriver_Enable(UART_PORT_T port)
{
    PinName tx_pin;
    PinName rx_pin;

    switch(port)
    {
        case 0:
            tx_pin = p13;
            rx_pin = p14;
            break;

        case 1:
            tx_pin = p28;
            rx_pin = p27;
            break;

        case 2:
            tx_pin = p9;
            rx_pin = p10;
            break;

        default:
            return STATUS_UART_BAD_PORT;
    }

    serial_init(&serial[port], tx_pin, rx_pin);
    serial_baud(&serial[port], baudrate[port]);
    serial_clear(&serial[port]);

    initialized[port] = TRUE;

    return STATUS_OK;
}

STATUS_T UARTDriver_Disable(UART_PORT_T port)
{
    if (port >= UART_NUM_PORTS)
        return STATUS_UART_BAD_PORT;

    initialized[port] = FALSE;

    return STATUS_OK;
}

STATUS_T UARTDriver_PutChar(UART_PORT_T port, char Val)
{
    if (port >= UART_NUM_PORTS)
        return STATUS_UART_BAD_PORT;

    serial_putc(&serial[port], Val);

    return STATUS_OK;
}

char UARTDriver_GetChar(UART_PORT_T port)
{
    if (port >= UART_NUM_PORTS)
        return 0x00;

    return serial_getc(&serial[port]);
}

BOOL UARTDriver_Connected(UART_PORT_T port)
{
    if (port >= UART_NUM_PORTS)
        return FALSE;

    return initialized[port];
}

BOOL UARTDriver_OkayToRead(UART_PORT_T port)
{
    if (port >= UART_NUM_PORTS)
        return FALSE;

    return (serial_readable(&serial[port]));
}

BOOL UARTDriver_OkayToWrite(UART_PORT_T port)
{
    if (port >= UART_NUM_PORTS)
        return FALSE;

    return (serial_writable(&serial[port]));
}
