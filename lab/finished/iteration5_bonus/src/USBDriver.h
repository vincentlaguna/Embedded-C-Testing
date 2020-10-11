#ifndef _USBDRIVER_H
#define _USBDRIVER_H

void USBDriver_Init(void);
void USBDriver_Exec(void);
BOOL USBDriver_PutChar(char Val);
char USBDriver_GetChar(void);

BOOL USBDriver_Connected(void);
BOOL USBDriver_OkayToRead(void);

#endif // _USBDRIVER_H
