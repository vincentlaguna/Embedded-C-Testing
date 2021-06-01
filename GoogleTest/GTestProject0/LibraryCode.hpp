#pragma once
// #include <vector>

/**********PARAMETIZED TEST CASES**********

class Validator
{
  public:
    
    Validator(int low, int high);
    bool inRange(int valueToTest);
    
  private:
    
    int mLow, mhigh;
};

/******************************************/


/**********ACCOUNT CLASS TEST CASES**********

class Account
{
  public:
    Account();
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
    void transfer(Account &to, double amount);
  private:
    double mBalance;
};

/********************************************/



/**********SIMPLE TEST CASES**********

// Simple Function Definition

int add(int a, int b);

double mySqrt(double x);

int countPositives(std::vector<int> const &inputVector);

void toUpper(char *inputString);

/*************************************/