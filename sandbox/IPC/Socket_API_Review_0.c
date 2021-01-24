// This file is to review the Socket API
// Struct sockaddr definition:
struct sockaddr
{
  unsigned short        sa_family; // AF_INET (most used), AF_UNIX, AF_NS, AF_IMPLINK
  char                  sa_data[14]; // Protocol-specific address
};

struct in_addr // Only used as a structure field; holds 32-bit netid/hostid
{
  unsigned long         s_addr;
};

struct sockaddr_in
{
  short int             sin_family;
  unsigned short int    sin_port;
  struct in_addr        sin_addr;
  unsigned char         sin_zero[8];
};

struct hostent // Keeps information relating to a Server
{
  char                 *h_name;
  char                **h_aliases;
  int                   h_addrtype;
  int                   h_length;
  char                **h_addr_list;
  
#define h_addr h_addr_list[0]
};

// Steps in using sockets to communicate:

// 1. create a new socket for network communication ("socket") - Open socket
// 2. Attach a local address to a socket ("bind") - Server Only
// 3. Announce willingness to connect ("listen") - On Server
// 4. Block caller until a connection request arrives ("accept") - 
// 5. Actively attempt to establish a connection request ("connect") - Client initiates this step
// 6. Send some data over connection ("send")
// 7. Receive some data over connection ("receive")
// 8. Release the connection ("close")

// Remember: Socket, Bind, Listen, Accept, Connect, Send, Receive, Close
// Working with sockets is similar to working with file:
// socket() and accept() functions both return handles (file descriptors) r/w

// Socket Functions:

// 1. socket()
// 2. connect() - Client Programs
// 3. bind() - Server Only
// 4. listen() and accept()
// 5. read(), recv(), recvfrom() or recvmesg()
// 6. write(), send(), sendto() or sendmsg()
// 7. close() and shutdown()

// Remember: All of the above functions require <sys/types.h>, <sys/sockets.h>
// #includes, except for read/write/close, which are defined in <unistd.h>

int socket(int family/*i.e., AF_INET - IPv4*/, int type/*i.e., SOCK_STREAM*/,
           int protocol/*i.e., IPPROTO_TCP/UDP/SCTP*/); // Returns socket descriptor
int setsockopt(int sockfd, int level, int optname,
               const void *optval, socklen_t optlen); // Manipulate options
int connect(int sockfd/*socket descriptor returned from socket()*/,
            struct sockaddr *serv_addr/*ptr to sockaddr containing dest. IP/port*/,
            int addrlen);
