#ifndef _CAPTURE_H
#define _CAPTURE_H

void     Capture_Init(void);
void     Capture_Exec(void);
STATUS_T Capture_GetResult(uint8_t* buffer, uint8_t* len, uint8_t maxLen);
STATUS_T Capture_Reset(void);
int      Capture_HasResults(void);

#endif // _CAPTURE_H
