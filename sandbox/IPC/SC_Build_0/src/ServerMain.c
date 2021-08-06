/*****************************************************************************
* Author(s):                                                                 *
*                                                                            *
* File:		ServerMain.c                                                         *
*                                                                            *
* Description: Server-side Main                                              *
*                                                                            *
*****************************************************************************/


/* Includes: ****************************************************************/

#include  "T_Server.h"

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
  uint16_t  uSrvSok       = 0; 
  uint16_t  sock          = 0; 
  uint16_t  clLen         = 0;
  
  S_SADDR   cL;
  // Initialize message buffers
  char      msg[100]      = {0};
  char      clMsg[200]    = {0};
  
  // File OPS
  FILE *fp;
  fp = fopen("../Client-Server/ServerLog_0.txt", "w+");
  //const char *pMsg = "<<< This message is from SERVER_0 >>>";
  // Create Socket
  socket_desc = createSocket();
  
  if(socket_desc == -1)
  {
    printf("\nCreation of SOCKET Failed.\n");
    return 1;
  }
  printf("\n<<< The SOCKET has been created >>>\n\n");
  // Bind
  if(bindCreatedServSocket(socket_desc) < 0)
  {
    perror("BIND Failed."); // Print the error message
    return 1;
  }
  printf("\n<<< BIND Done >>>\n\n");
  // Listen
  listen(socket_desc, 3); // Number of MAX connections
  // Accept incoming connections
// #ifdef _LOCAL_TEST
//   while(1)
//   {
// #endif
    printf("\n<<< Waiting for incoming connections...\n\n");
    clientLen = sizeof(struct sockaddr_in);
    // Accept connection from an incoming client
    sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&clientLen);
    
    if(sock < 0)
    {
      perror("ACCEPT Failed.");
      return 1;
    }
    printf("\nConnection ACCEPTED\n\n");
    // Message Buffers
    memset(clientMsg, '\0', sizeof clientMsg);
    memset(msg, '\0', sizeof msg);
    // Receive a reply from the Client
    if(recv(sock, clientMsg, 200, 0) < 0)
    {
      printf("\nRECEIVE Failed.\n");
    // #ifdef _LOCAL_TEST
    //   break;
    // #endif
    }
    printf("Client Reply: %s\n", clientMsg);
    //sprintf(local file to write to...)
    fprintf(fp, "Client Reply: %s\n", clientMsg);
   
 //#ifndef _LOCAL_TEST
    int i = atoi(clientMsg); // change to ouptut to a file and log
    i--;
    sprintf(msg, "%d", i);
    fprintf(fp, "Client 1 connected: %d", i);
   
    close(sock);
  //#endif
  
  // #ifdef _LOCAL_TEST 
  //   if(strncmp(pMsg, clientMsg) == 0)
  //   {
  //     strcpy(msg, "<<< This message is to confirm ACK >>>");
  //   }
  //   else
  //   {
  //     strcpy(msg, "INVALID MESSAGE!");
  //   }
  //   // Send some data
  //   if(send(sock, msg, strlen(msg), 0) < 0)
  //   {
  //     printf("\nSEND Failed.\n");
  //   }
  //   close(sock);
  //   sleep(1);
  // #endif  
  
  //#ifndef _LOCAL_TEST
    printf("\n<<< Waiting for incoming connections...\n");
    // Accept Connection from another incoming Client
    sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&clientLen);
   
    if(sock < 0)
    {
      perror("ACCEPT Failed.");
      return 1;
    }
    printf("\nConnection ACCEPTED\n\n");
    // Send some Data
    if(send(sock, msg, strlen(msg), 0) < 0)
    {
      printf("\nSEND Failed.\n");
      return 1;
    }
  //#endif
// #ifdef _LOCAL_TEST   
//   }
// #endif
  fclose(fp);
  return(0);
}

/****************************************************************************/

/****************************************************************************/
// End ServerMain.c
