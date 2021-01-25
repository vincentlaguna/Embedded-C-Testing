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
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

short createSocket(void)
{
  short servSocket;
  printf("\n<<< This is a simplified example of creating a Server-side "
         "socket for a TCP/IP connection >>>\n");
}

// int main(void)
// {
//     printf("\n<<< This is a simplified example of creating a Server-side "
//          "socket for TCP/IP connection >>>\n");
//     return(0);
// }