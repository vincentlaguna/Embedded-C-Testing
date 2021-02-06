// Client Steps in Pseudo-code:

// my_socket_descriptor = socket()
// their_socket_descriptor = connect(my_sd, <presumed address of some Server>)
// send(their_socket_descriptor, <stuff you want to send>)
// recv(their_socket_descriptor, <where to put what you receive>)
// close(my_sd)

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
// Create a socket for server communication
short createSocket(void)
{
  short clientSocket;
  printf("\n<<< Creation of Client-Side Socket >>>\n\n");
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  printf("\nSuccess!\n");
  return clientSocket;
}
// Try to connect to Server
int socketConnect(int clientSocket)
{
    
}