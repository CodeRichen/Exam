#include "rate.h"
int main() {
	SavingsAccount saver1(2000.00);
	SavingsAccount saver2(3000.00);
	SavingsAccount::modifyInterestRate(0.03);
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();
	cout << "2000,3%:"<<saver1.print()<<"\n";
	cout << "3000,3%:" << saver2.print() << "\n";
	SavingsAccount::modifyInterestRate(0.04);
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();
	cout << "2000,4%:" << saver1.print() << "\n";
	cout << "3000,4%:" << saver2.print() << "\n";
}