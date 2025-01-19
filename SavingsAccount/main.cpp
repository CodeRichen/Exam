#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

int main() {
    Account account(-100.0);
    cout << "<0 Initial Account balance: $" << account.getBalance() << endl;
    account.credit(50.0);
    cout << "After credit of $50.00, balance: $" << account.getBalance() << endl;
    account.debit(430.0);
    cout << "After debit of $430.00, balance: $" << account.getBalance() << endl;


    SavingsAccount savings(200.0, 0.3);
    cout << "\nSavingsAccount initial balance: $" << savings.getBalance() << endl;
    double interest = savings.calculateInterest();
    cout << "Interest earned: $" << interest << endl;
    savings.credit(interest);
    cout << "After adding interest, balance: $" << savings.getBalance() << endl;

    CheckingAccount checking(150.0, 2.0);
    cout << "\nCheckingAccount initial balance: $" << checking.getBalance() << endl;
    checking.credit(50.0);
    cout << "After credit of $50.00 (minus fee), balance: $" << checking.getBalance() << endl;
    checking.debit(30.0);
    cout << "After debit of $30.00 (minus fee), balance: $" << checking.getBalance() << endl;

    return 0;
}
