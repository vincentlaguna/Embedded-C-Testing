#ifndef BUFFER_H
#define BUFFER_H

typedef struct _BUFFER_T
{
    uint8_t* bytes;
    uint16_t max_size;
    uint16_t read_index;
    uint16_t write_index;
} BUFFER_T;

STATUS_T Buffer_Init(BUFFER_T* Buffer, uint8_t* Bytes, uint16_t MaxSize);
STATUS_T Buffer_Put(BUFFER_T* Buffer, uint8_t Val);
STATUS_T Buffer_Get(BUFFER_T* Buffer, uint8_t* Val);
STATUS_T Buffer_Peek(BUFFER_T* Buffer, uint8_t* Val);
int      Buffer_IsFull(BUFFER_T* Buffer);
int      Buffer_IsEmpty(BUFFER_T* Buffer);
void     Buffer_Clear(BUFFER_T* Buffer);

#endif //BUFFER_H
