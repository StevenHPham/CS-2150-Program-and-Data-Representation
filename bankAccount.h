#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>

using namespace std;

//Class declaration
class bankAccount {
public:
 bankAccount();
 bankAccount(double amount);
 ~bankAccount();

 double getBalance();
 double withdraw(double amount);
 double deposit(double amount);
 
private:
 double balance;

};

#endif


