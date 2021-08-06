/*****************************************************************************
Author(s):

File:		T_TEST.H

*****************************************************************************/

/* INCLUDES: ****************************************************************/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <sys/socket.h>
#include  <arpa/inet.h>
#include  <unistd.h>

/****************************************************************************/

/* DEFINES: ****************************************************************/

#define	TEST_PORT     12345
#define LOCAL_TEST

/****************************************************************************/

/* TYPEDEFS: ****************************************************************/

/* Data Buffer **************************************************************/
//
typedef	struct        DataBuffer
{
	uint32_t					  uBufferType;		// Type of Buffer	
	ServEntry*			    pSrvEntry;		  // Pointer to the Data Buffer
	uint32_t					  ulFlags;			  // TBD
	uint32_t					  uDataSize;		  // Size of data
	uint32_t					  uBufferSize;		// Buffer size
	uint32_t					  uHead;					// Head
	uint32_t					  uTail;					// Tail
	uint8_t*					  pBuffer;				// This Buffer

} DataBuffer_t;

/****************************************************************************/

/* PROTOTYPES: *************************************************************/