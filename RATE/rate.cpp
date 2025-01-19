#include "rate.h"
float SavingsAccount::annualInterestRate = 0.00;
SavingsAccount::SavingsAccount(int money) {
	save(money);
}
void SavingsAccount::save(int money) {
	savingsBalance = money;
}
void SavingsAccount::modifyInterestRate(float rate) {
	annualInterestRate = rate;
}
void SavingsAccount::calculateMonthlyInterest() {
	savingsBalance += (savingsBalance * annualInterestRate/ 12);
}
float SavingsAccount::print() {
	return savingsBalance;
}