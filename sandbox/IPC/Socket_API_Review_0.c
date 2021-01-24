// This file is to review the Socket API
// Struct sockaddr definition:
struct sockaddr
{
  unsigned short sa_family; // AF_INET (most used), AF_UNIX, AF_NS, AF_IMPLINK
  char           sa_data[14]; // Protocol-specific address
};

struct sockaddr_in
{
  short int             sin_family;
  unsigned short int    sin_port;
  struct in_addr        sin_addr;
  unsigned char         sin_zero[8];
};