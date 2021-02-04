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
// end loop
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
// Helper Functions
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
  int clientPort = 12345; // Needs to be greater than sys ports (>1024)
  
  struct sockaddr_in remote = {0};
  // Internet address family
  remote.sin_family = AF_INET;
  // Any incoming interface
  // The htonl() function converts the unsigned integer hostlong from 
  // host byte order to network byte order
  remote.sin_addr.sin_addr = htonl(INADDR_ANY);
  // The htons function takes a 16-bit number in host byte order 
  // and returns a 16-bit number in network byte order used in 
  // TCP/IP networks (the AF_INET or AF_INET6 address family)
  remote.sin_port = htons(clientPort); // Local Port
  
  iRetVal = bind(servSocket, (struct sockaddr *)&remote, sizeof(remote));
  return iRetVal;
}

int main(int argc, char *argv[])
{
  int socket_desc = 0, sock = 0; clientLen = 0;
  struct sockaddr_in client;
  // Initialize message buffers
  char clientMsg[200] = {0};
  char msg[100] = {0};
  const char *pMsg = "<<< This message is from SERVER_0 >>>";
  // Create Socket
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
  while(1)
  {
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
   memset(clientMsg, '\0', sizeof(clientMsg));
   memset(message, '\0', sizeof(message));
   // Receive a reply from the Client
   if(recv(sock, clientMsg, 200, 0) < 0)
   {
     printf("\nRECEIVE Failed.\n");
     break;
   }
   printf("\nClient Reply: %s\n\n", clientMsg);
   
   if(strcmp(pMsg, clientMsg) == 0)
   {
     strcpy(message, "<<< This message is to confirm ACK >>>");
   }
   else
   {
     
   }
  }
  return(0);
}