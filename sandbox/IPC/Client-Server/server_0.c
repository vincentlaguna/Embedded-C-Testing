// Server steps in Pseudo-code (iterative Server):

// my_socket_descriptor = socket()
// bind(my_sd, <local address, mainly a port number>)
// listen(my_socket_descriptor)

// start loop
// {
//     their_socket_descriptor = accept(my_socket_descriptor,
//                                      <empty address to be filled with
//                                      their incoming info>)
//     recv(their_socket_descriptor, <where to put what you receive>)
//     send(their_socket_descriptor, <the stuff you want to send>)
//     close(my_socket_descriptor)
// }
// end loop
