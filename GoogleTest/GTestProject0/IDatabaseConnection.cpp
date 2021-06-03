#include    "IDatabaseConnection.hpp"
#include    <iostream>

IDatabaseConnection::IDatabaseConnection(std::string serverAddress) 
    : mServerAddress{serverAddress} {}

void  IDatabaseConnection::connect()
{
  std::cout << "Connecting to Database Server " << serverAddress << "\n";
  // Initialize real database connection
}

void  IDatabaseConnection::disconnect()
{
  std::cout << "Disconnecting from Database\n";
  // Close real database connection
}