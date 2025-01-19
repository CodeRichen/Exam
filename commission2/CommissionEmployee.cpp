#include <iostream>
#include "CommissionEmployee.h"
using namespace std;

// constructor
CommissionEmployee::CommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate)
    : firstName(first), lastName(last), socialSecurityNumber(ssn) {
    setGrossSales(sales); // validate and store gross sales
    setCommissionRate(rate); // validate and store commission rate

    cout << "CommissionEmployee constructor: " << endl;
    print();
    cout << "\n\n";
} // end CommissionEmployee constructor

// destructor
CommissionEmployee::~CommissionEmployee() {
    cout << "CommissionEmployee destructor: " << endl;
    print();
    cout << "\n\n";
} // end CommissionEmployee destructor

// 設定總銷售額
void CommissionEmployee::setGrossSales(double sales) {
    grossSales = (sales < 0.0) ? 0.0 : sales;
}

// 返回總銷售額
double CommissionEmployee::getGrossSales() const {
    return grossSales;
}

// 設定佣金比例
void CommissionEmployee::setCommissionRate(double rate) {
    commissionRate = (rate < 0.0) ? 0.0 : rate;
}

// 返回佣金比例
double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

// 計算收入
double CommissionEmployee::earnings() const {
    return getGrossSales() * getCommissionRate();
}

// 列印員工資訊
void CommissionEmployee::print() const {
    cout << "commission employee: " << getFirstName() << " " << getLastName() << "\n"
        << "social security number: " << getSocialSecurityNumber() << "\n"
        << "gross sales: " << getGrossSales() << "\n"
        << "commission rate: " << getCommissionRate() << "\n";
}

// 返回名
string CommissionEmployee::getFirstName() const {
    return firstName; // 返回 firstName
}

// 返回姓
string CommissionEmployee::getLastName() const {
    return lastName; // 返回 lastName
}

// 返回社會安全號碼
string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber; // 返回 socialSecurityNumber
}
