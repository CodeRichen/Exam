#include "CheckingAccount.h"


CheckingAccount::CheckingAccount(double initialBalance, double fee)
    : Account(initialBalance) {
    transactionFee = fee;
}


void CheckingAccount::credit(double amount) {
    Account::credit(amount);
    balance -= transactionFee; 
}


bool CheckingAccount::debit(double amount) {
    if (Account::debit(amount)) {//根據返回值決定是否應扣除交易費用。
        balance -= transactionFee; 
        return true;
    }
    return false;
}
