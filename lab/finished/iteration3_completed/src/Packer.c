#include "Core.h"
#include "Packer.h"

static char buffer[PACKER_MAX_LEN];

char* Packer_AddMsg(char Cmd, char* Data, uint8_t Len)
{
    uint8_t i = 0;

    if (Len > 35)
        return NULL;
    if ((Cmd < 'A') || (Cmd > 'Z'))
        return NULL;
    if ((Len > 0) && (Data == NULL))
        return NULL;

    buffer[i++] = '[';
    buffer[i++] = Cmd;
    if (Len <= 9)
        buffer[i++] = (Len + '0');
    else
        buffer[i++] = (Len - 10 + 'A');
    while(Len--)
    {
        buffer[i++] = *Data++;
        buffer[i++] = *Data++;
    }
    buffer[i++] = ']';
    buffer[i++] = 0;

    return buffer;
}
