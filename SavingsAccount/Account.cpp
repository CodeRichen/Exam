#include "Account.h"
#include <iostream>

Account::Account(double initialBalance) {
    if (initialBalance >= 0.0) {
        balance = initialBalance;
    }
    else {
        balance = 0.0;
        cout << "Debit amount exceeded account balance." << endl;
    }
}


void Account::credit(double amount) {
    balance += amount;
}


bool Account::debit(double amount) {
    if (amount > balance) {
        cout << "Debit amount exceeded account balance." << endl;
        return false;
        
    }
    balance -= amount;
    return true;
}


double Account::getBalance() const {
    return balance;
}
