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
#define TEST_PORT 12345
#ifdef _LOCAL_TEST
  #define LOCAL "127.0.0.1"
#endif
// Helper Functions
// Create a Socket for Server Communication
short createSocket(void)
{
  short clientSocket_1;
  printf("\n<<< Creation of Client-Side Socket >>>\n\n");
  clientSocket_1 = socket(AF_INET, SOCK_STREAM, 0);
  printf("\nSuccess!\n");
  return clientSocket_1;
}
// Try to Connect to Server
int socketConnect(int clientSocket_1)
{
  int iRetVal = -1;
  int serverPort = TEST_PORT;
  struct sockaddr_in remote = {0};
  remote.sin_family = AF_INET;
  remote.sin_addr.s_addr = inet_addr(LOCAL);
  remote.sin_port = htons(serverPort);
}