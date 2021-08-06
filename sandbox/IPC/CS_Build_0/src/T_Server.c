/*****************************************************************************
* Author(s):                                                                 *
*                                                                            *
* File:		T_Server.c                                                         *
*                                                                            *
* Description: Server-side code                                              *
*                                                                            *
*****************************************************************************/

/* Includes: ****************************************************************/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <sys/socket.h>
#include  <arpa/inet.h>
#include  <unistd.h>

/****************************************************************************/

/* Defines: ****************************************************************/

#define	TEST_PORT     12345
#define LOCAL_TEST

/****************************************************************************/

/* Data Sructure Definitions: ***********************************************/

/* Data Buffer **************************************************************/

typedef	struct        DataBuffer
{
	uint32_t					  uBufferType;		// Type of Buffer	
// 	ServEntry*			    pSrvEntry;		  // Pointer to the Data Buffer <TBD>
	uint32_t					  uDataSize;		  // Size of data
	uint32_t					  uBufferSize;		// Buffer size
	uint32_t					  *pHead;					// Head
	uint32_t					  *pTail;					// Tail
	uint8_t*					  pBuffer;				// This Buffer

} DataBuffer_t;

/****************************************************************************/

/* Function Definitions: ****************************************************/
// Helper Functions

/*****************************************************************************
*                                                                            *
* Name:			  SokInit_Handlr(void)                                           *
* Purpose:    Handles the creation of a Socket                               *
* Parameters: None                                                           *  
* Returns:		Unsigned 16-bit integer                                        *
*                                                                            *
*****************************************************************************/

uint16_t	SokInit_Handlr(void)
{
  
}

// End 
/****************************************************************************/
uint32_t	BindSrvSok_Hndlr(uint32_t uSrvSok);

/****************************************************************************/
// End T_Server.c
