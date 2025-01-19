#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;


class Account {
protected:
    double balance; 

public:
    
    Account(double initialBalance);


    virtual void credit(double amount);


    virtual bool debit(double amount);


    double getBalance() const;

    virtual ~Account() {}
};

#endif
