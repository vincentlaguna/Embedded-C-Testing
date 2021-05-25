#pragma once
// #include <vector>
// Move unto implementing classes here or new lib.hpp

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

// Simple Function Definition
// int add(int a, int b);

// double mySqrt(double x);

// int countPositives(std::vector<int> const &inputVector);

// void toUpper(char *inputString);
