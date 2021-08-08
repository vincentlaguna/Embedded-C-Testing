/*****************************************************************************
* Author(s):                                                                 *
*                                                                            *
* File:		ClientMain.c                                                       *
*                                                                            *
* Description: Client-side Main                                              *
*                                                                            *
*****************************************************************************/


/* Includes: ****************************************************************/

#include  "../inc/T_SCCommon.h"

/****************************************************************************/

/* Defines: *****************************************************************/
/****************************************************************************/

/* Typedefs: ****************************************************************/
/****************************************************************************/

/* Main Starts Here: ********************************************************/
//
int main(int argc, char *argv[])
{
  // Initialize Local Variables
  uint16_t    uClSok        = 0; 
  uint16_t    sok           = 0; 
  uint16_t    clLen         = 0;
  // This is where we fill-in the Server-Side address info
  S_SADDR_IN  Srv; 
  // Initialize buffers to store the data
  // char        sndToSrv[100] = {"Client (n) Connected"};
  // char        srvReply[200] = {0};
  DataBuffer_t  ClDbuff;
  DataBuffer_t  SrvRspDbuff;
  // Create Socket
  uClSok                    = SokInit_Handlr();
  // Error Handling
  if (uClSok == -1)
  {
    printf("\nCreation of SOCKET Failed.\n");
    return EXIT_FAILURE;
  }
  
  sleep(1);
  
  printf("\n>>> The SOCKET has been created >>>\n\n");
  // Bind
  if (SokConnect_Hndlr(uClSok) < 0)
  {
    perror("CONNECT Failed."); // Print the error message
    return EXIT_FAILURE;
  }
  
  sleep(1);
  
  printf("Connection to Remote Server = Successful\n\n");
  
  // printf("Please Enter the Message: ");
  // fgets(sndToSrv, 100, stdin);
  
  // sleep(1);
  // // Send data to the Remote Server 
  // SokSend_Hndlr(uClSok, sndToSrv, strlen(sndToSrv));
  // // Received the data from the Remote Server
  // SokRcv_Hndlr(uClSok, srvReply, 200);
  // // Output Server Response
  // printf("\nServer Response: %s\n\n", srvReply);
  
  uint32_t  DbuffSize    = sizeof(DataBuffer_t);
  printf("Please Enter the Message: ");
  fgets(ClDbuff.cPayload, DbuffSize, stdin);
  
  sleep(1);
  // Send data to the Remote Server 
  SokSend_Hndlr(uClSok, ClDbuff.cPayload, DbuffSize);
  // Received the data from the Remote Server
  SokRcv_Hndlr(uClSok, SrvRspDbuff.cPayload, DbuffSize);
  // Output Server Response
  printf("\nServer Response: %s\n\n", SrvRspDbuff.cPayload);
  // Close the Client Socket
  close(uClSok);
  
  return(0);

}

/****************************************************************************/

/****************************************************************************/
// End ServerMain.c
