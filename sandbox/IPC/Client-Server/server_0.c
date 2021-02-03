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
  
  return(0);
}