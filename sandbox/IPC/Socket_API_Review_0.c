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

