#pragma     once
#include    "Employee.hpp"

#include    <string>
#include    <vector>

// Interface: because we might sub-class it...
// Example: IOracleDatabaseConnectionManager, ISQLDatabaseConnectionManager

class       IDatabaseConnection
{
  public:
    
    IDatabaseConnection(std::string serverAddress);
    
    // virtual float  getSalary(int id) const = 0; // SELECT * FROM employees WHERE id=...
    // virtual void   updateSalary(int id, float newSalary) = 0;
    
    // virtual std::vector<Employee>  getSalariesRange(float low) const = 0; // Just > low
    // virtual std::vector<Employee>  getSalariesRange(float low, float high) const = 0;
    
    virtual void  connect();
    virtual void  disconnect();

  protected:
    
    std::string mServerAddress;  
};
