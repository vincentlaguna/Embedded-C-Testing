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
#define _LOCAL_TEST
#ifdef _LOCAL_TEST
  #define LOCAL "127.0.0.1"
#endif
// Helper Functions
// Create a socket for server communication
short createSocket(void)
{
  short clientSocket;
  printf("\n<<< Creation of Client-Side Socket >>>\n\n");
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  printf("Success!\n");
  return clientSocket;
}
// Try to connect to Server
int socketConnect(int clientSocket)
{
  int iRetVal = -1;
  int serverPort = TEST_PORT; // Match the "clientPort" on Server-Side code
  
  struct sockaddr_in remote = {0};
  // Internet address family
  remote.sin_family = AF_INET;
  // Any incoming interface
  // The htonl() function converts the unsigned integer hostlong from 
  // host byte order to network byte order
  remote.sin_addr.s_addr = inet_addr(LOCAL); // Server address (local host = testing)
  // The htons function takes a 16-bit number in host byte order 
  // and returns a 16-bit number in network byte order used in 
  // TCP/IP networks (the AF_INET or AF_INET6 address family)
  remote.sin_port = htons(serverPort); // Note the opposite on Server-Side code
  
  iRetVal = connect(clientSocket, (struct sockaddr *)&remote, sizeof(struct sockaddr_in));
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
  shortRetVal = send(clientSocket, pRqst, lenpRqst, 0);
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
  int clientSocket = 0; 
  //int readSize = 0;
  struct sockaddr_in Server; // This is where we fill-in the Server-Side address info
  //int sendToServer = 1;
  char sendToServer[100] = {"Client 1 Connected"};
  char serverReply[100] = {0};
  // Create the Socket
  clientSocket = createSocket();
  
  if(clientSocket == -1)
  {
    printf("\nClient Socket Creation Failed.\n");
    return 1;
  }
  printf("\nCreation of Client Socket = Successful\n\n");
  // Connect to the Remote Server
  if(socketConnect(clientSocket) < 0)
  {
    perror("CONNECT Failed.");
    return 1;
  }
  printf("Connection to Remote Server = Successful\n\n");
  //printf("Please Enter the Message: ");
  //fgets(sendToServer, 100, stdin);
  fprintf(sendToServer, 100, sendToServer);
  // Find a way to induce the data into a variable and send to server
  // Send data to the Remote Server // Somthing is wrong here, it closes...
  socketSend(clientSocket, sendToServer, strlen(sendToServer));
  //socketSend(clientSocket, sendToServer, sizeof(int));
  // Received the data from the Remote Server
  //readSize = socketReceive(clientSocket, serverReply, 200);
  //printf("\nServer Response: %s\n\n", serverReply);
  
  
  close(clientSocket);
  
  return(0);
}
// Continue the open communication, maybe write to a file?