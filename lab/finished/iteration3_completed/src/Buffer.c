#include "Core.h"
#include "Buffer.h"

STATUS_T Buffer_Init(BUFFER_T* Buffer, uint8_t* Bytes, uint16_t MaxSize)
{
    if (Buffer == 0)
        return STATUS_NULL_POINTER;
    if (Bytes == 0)
        return STATUS_NULL_POINTER;
    if (MaxSize < 2)
        return STATUS_TOO_LOW;

    Buffer->bytes       = Bytes;
    Buffer->max_size    = MaxSize;
    Buffer->write_index = 0;
    Buffer->read_index  = 0;

    return STATUS_OK;
}

STATUS_T Buffer_Put(BUFFER_T* Buffer, uint8_t Val)
{
    uint16_t NextWrite = (Buffer->write_index + 1) % (Buffer->max_size);
    if (0 == Buffer->bytes)
        return STATUS_NOT_INITIALIZED;
    if (NextWrite == Buffer->read_index)
        return STATUS_OVERFLOW;
    Buffer->bytes[ Buffer->write_index ] = Val;
    Buffer->write_index = NextWrite;
    return STATUS_OK;
}

STATUS_T Buffer_Get(BUFFER_T* Buffer, uint8_t* Val)
{
    if (0 == Buffer->bytes)
        return STATUS_NOT_INITIALIZED;
    if (Buffer->read_index == Buffer->write_index)
        return STATUS_NONE_YET;
    *Val = Buffer->bytes[ Buffer->read_index ];
    Buffer->read_index = (Buffer->read_index + 1) % Buffer->max_size;
    return STATUS_OK;
}

STATUS_T Buffer_Peek(BUFFER_T* Buffer, uint8_t* Val)
{
    if (0 == Buffer->bytes)
        return STATUS_NOT_INITIALIZED;
    if (Buffer->read_index == Buffer->write_index)
        return STATUS_NONE_YET;
    *Val = Buffer->bytes[ Buffer->read_index ];
    return STATUS_OK;
}

int Buffer_IsFull(BUFFER_T* Buffer)
{
    uint16_t NextWrite = (Buffer->write_index + 1) % (Buffer->max_size);
    return (NextWrite == Buffer->read_index);
}

int Buffer_IsEmpty(BUFFER_T* Buffer)
{
    return (Buffer->read_index == Buffer->write_index);
}

void Buffer_Clear(BUFFER_T* Buffer)
{
    Buffer->read_index = Buffer->write_index;
}
