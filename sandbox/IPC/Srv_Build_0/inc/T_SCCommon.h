/*****************************************************************************
* Author(s):                                                                 *
*                                                                            *
* File:		T_SCCommon.h                                                       *
*                                                                            *
* Description: Server-Client side code common header file                    *
*                                                                            *
*****************************************************************************/
// Header Include Guards
#ifndef		T_SCCommon_H
#define 	T_SCCommon_H

/* Includes: ****************************************************************/

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <sys/socket.h>
#include  <arpa/inet.h>
#include  <unistd.h>

/****************************************************************************/

/* Defines: *****************************************************************/

#define LOCAL_TEST
#define	TEST_PORT     					12345
#define	S_SADDR	   struct				sockaddr
#define S_SADDR_IN struct    		sockaddr_in
#define TIME_V		 struct				timeval
#define LOCAL_IP								"127.0.0.1"

/****************************************************************************/

/* Data Sructure Definitions: ***********************************************/

/* Data Buffer **************************************************************/

typedef	struct        					DataBuffer
{
	uint32_t					  					uBufferType;		// Type of Buffer	
// 	ServEntry*			  		  		pSrvEntry;		  // Pointer to the Data Buffer <TBD>
	uint32_t					  					uDataSize;		  // Size of data
	uint32_t					  					uBufferSize;		// Buffer size
	uint32_t					  					*pHead;					// Head
	uint32_t					  					*pTail;					// Tail
	uint8_t*					  					pBuffer;				// This Buffer

} DataBuffer_t;

/****************************************************************************/

/* Function Prototypes: *****************************************************/
// Helper Functions

uint16_t	SokInit_Handlr(void);
uint32_t	BindSrvSok_Hndlr(uint32_t uSrvSok);
uint32_t	SokConnect_Hndlr(uint32_t uClSok);
uint32_t	SokSend_Hndlr(uint32_t uClSok, char *pRqst, uint16_t pRqstLen);
uint32_t	SokRcv_Hndlr(uint32_t uClSok, char *pRsp, uint16_t rcvSize);

/****************************************************************************/
#endif // T_SCCommon_H