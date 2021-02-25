// Server steps in Pseudo-code (iterative Server):

// my_socket_descriptor = socket()
// bind(my_sd, <local address, mainly a port number>)
// listen(my_socket_descriptor)

// start loop
// {
//   their_socket_descriptor = accept(my_socket_descriptor,
//                                    <empty address to be filled with
//                                    their incoming info>)
//   recv(their_socket_descriptor, <where to put what you receive>)
//   send(their_socket_descriptor, <the stuff you want to send>)
//   close(my_socket_descriptor)
// }
// End loop
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define TEST_PORT 12345
//#define _LOCAL_TEST
// Helper Functions
short createSocket(void);
int bindCreatedServSocket(int servSocket);
// Main Driver Program for Server
int main(int argc, char *argv[])
{
  int socket_desc = 0, sock = 0, clientLen = 0;
  struct sockaddr_in client;
  // Initialize message buffers
  char clientMsg[200] = {0};
  char msg[100] = {0};
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
   
 //#ifndef _LOCAL_TEST
    int i = atoi(clientMsg); // change to ouptut to a file and log
    i--;
    sprintf(msg, "%d", i);
   
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
  return(0);
}

short createSocket(void) // Create local Server Socket (Streaming Socket)
{
  short servSocket = 0;
  printf("\n<<< This is a simplified example of creating a Server-side "
         "socket for a TCP/IP connection >>>\n\n");
  servSocket = socket(AF_INET, SOCK_STREAM, 0);
  printf("\n<<< Created Server-Side Socket >>>\n\n");

  return servSocket;
}

int bindCreatedServSocket(int servSocket) // Wraps the bind() call
{
  int iRetVal = -1;
  int clientPort = TEST_PORT; // Needs to be greater than sys ports (>1024)
  
  struct sockaddr_in remote = {0};
  // Internet address family
  remote.sin_family = AF_INET;
  // Any incoming interface
  // The htonl() function converts the unsigned integer hostlong from 
  // host byte order to network byte order
  remote.sin_addr.s_addr = htonl(INADDR_ANY);
  // The htons function takes a 16-bit number in host byte order 
  // and returns a 16-bit number in network byte order used in 
  // TCP/IP networks (the AF_INET or AF_INET6 address family)
  remote.sin_port = htons(clientPort); // Local Port
  
  iRetVal = bind(servSocket, (struct sockaddr *)&remote, sizeof(remote));
  return iRetVal;
}