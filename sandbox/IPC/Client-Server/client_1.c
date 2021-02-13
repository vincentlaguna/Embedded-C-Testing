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
  iRetVal = connect(clientSocket_1, (struct sockaddr *)&remote, sizeof(struct sockaddr_in));
  return iRetVal;
}
// Receive Data from the Server
int socketReceive(int clientSocket_1, char *pRsp, short recvSize)
{
  int shortRetVal = -1;
  struct timeval timeValue
  timeValue.tv_sec = 20;
  timeValue.tv_usec = 0;
  
  if(setsockopt(clientSocket_1, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeValue, sizeof(timeValue)) < 0)
  {
    printf("\nTIME OUT.\n");
    return -1;
  }
  shortRetVal = recv(clientSocket_1, pRsp, recvSize, 0);
  printf("\nResponse %s\n", pRsp);
  return shortRetVal;
}
// Main Driver Program
int main(int argc, char *arg[])
{
  int clientSocket_1 = 0, readSize = 0;
  struct soackaddr_in Server;
  return (0);
}