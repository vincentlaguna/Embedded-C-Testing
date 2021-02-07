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
// Helper Functions
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
  int iRetVal = -1;
  int serverPort = 12345 // Match the "clientPort" on Server-Side code
  
  struct sockaddr_in remote = {0};
  // Internet address family
  remote.sin_family = AF_INET;
  // Any incoming interface
  // The htonl() function converts the unsigned integer hostlong from 
  // host byte order to network byte order
  remote.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server address (local host = testing)
  // The htons function takes a 16-bit number in host byte order 
  // and returns a 16-bit number in network byte order used in 
  // TCP/IP networks (the AF_INET or AF_INET6 address family)
  remote.sin_port = htons(serverPort); // Note the opposite on Server-Side code
  
  iRetVal = connect(clientSocket, (struct sockaddr *)&remote, sizeof(remote));
  return iRetVal;
}
// Send the data to the server and set the timeout of 20 seconds
int socketSend(int clientSocket, char *pRqst, short lenpRqst)
{
  int shortRetVal = -1;
  struct timeval timeValue;
  timeValue.tv_sec = 20; // 20 Second time-out
  timeValue.tv_usec = 0;
  
  if(setsockopt(clientSocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeValue, sizeof(timeValue)) < 0)
  {
    printf("\nTIME OUT.\n");
    return -1;
  }
  // Calling send() to send the request to the Server
  shortRetVal = send(clientSocket, pRqst, 0);
  return shortRetVal;
}
// Receive data from the Server
int socketReceive(int clientSocket, char *pRsp, short recvSize)
{
  int shortRetVal = -1;
  struct timeval timeValue;
  timeValue.tv_sec = 20; // 20 Second time-out
  timeValue.tv_usec = 0;
  
  if(setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeValue, sizeof(timeValue)) < 0)
  {
    printf("\nTIME OUT.\n");
    return -1;
  }
  shortRetVal = recv(clientSocket, pRsp, recvSize, 0);
  printf("\nResponse %s\n", pRsp);
  return shortRetVal;
}
// Main Driver Program
int main(void)
{
  
  return(0);
}