
#include "Core.h"
#include "USBDriver.h"
#include "Buffer.h"
#include "serial_api.h"

#define USB_BUFFER_MAX    (75)

static BOOL     initialized = FALSE;
STATIC serial_t USBDriver_serial;
STATIC uint8_t  tx_data[USB_BUFFER_MAX];
STATIC uint8_t  rx_data[USB_BUFFER_MAX];
STATIC BUFFER_T tx;
STATIC BUFFER_T rx;

void USBDriver_Init(void)
{
    serial_init(&USBDriver_serial, USBTX, USBRX);
    serial_clear(&USBDriver_serial);

    Buffer_Init(&tx, tx_data, USB_BUFFER_MAX);
    Buffer_Init(&rx, rx_data, USB_BUFFER_MAX);

    initialized = TRUE;
}

void USBDriver_Exec(void)
{
    uint8_t Val;

    //When the tx fifo is empty and we have tx data in the buffer, move data
    while (serial_writable(&USBDriver_serial) && (!Buffer_IsEmpty(&tx)) && (STATUS_OK == Buffer_Get(&tx, &Val)))
    {
        serial_putc(&USBDriver_serial, Val);
    }

    //When the rx fifo has data and the rx buffer isn't full, move data
    while (serial_readable(&USBDriver_serial) && !Buffer_IsFull(&rx))
    {
        Val = serial_getc(&USBDriver_serial);
        Buffer_Put(&rx, Val);
    }
}

BOOL USBDriver_PutChar(char Val)
{
    if (Buffer_IsFull(&tx))
        return FALSE;

    Buffer_Put(&tx, Val);

    return TRUE;
}

char USBDriver_GetChar(void)
{
    uint8_t Val;
    if (Buffer_Get(&rx, &Val) == STATUS_OK)
        return (char)Val;
    else
        return 0x00;
}

BOOL USBDriver_Connected(void)
{
    return initialized;
}

BOOL USBDriver_OkayToRead(void)
{
    return (!Buffer_IsEmpty(&rx));
}

