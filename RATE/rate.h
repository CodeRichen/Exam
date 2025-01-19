#include <iostream>
using namespace std;
class SavingsAccount{
public:
	SavingsAccount(int money);
	void save(int money);
	void calculateMonthlyInterest();
	float print();
	static void modifyInterestRate(float rate);
private:
	float savingsBalance;
	static float annualInterestRate;
	};