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

// �]�w�`�P���B
void CommissionEmployee::setGrossSales(double sales) {
    grossSales = (sales < 0.0) ? 0.0 : sales;
}

// ��^�`�P���B
double CommissionEmployee::getGrossSales() const {
    return grossSales;
}

// �]�w�������
void CommissionEmployee::setCommissionRate(double rate) {
    commissionRate = (rate < 0.0) ? 0.0 : rate;
}

// ��^�������
double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

// �p�⦬�J
double CommissionEmployee::earnings() const {
    return getGrossSales() * getCommissionRate();
}

// �C�L���u��T
void CommissionEmployee::print() const {
    cout << "commission employee: " << getFirstName() << " " << getLastName() << "\n"
        << "social security number: " << getSocialSecurityNumber() << "\n"
        << "gross sales: " << getGrossSales() << "\n"
        << "commission rate: " << getCommissionRate() << "\n";
}

// ��^�W
string CommissionEmployee::getFirstName() const {
    return firstName; // ��^ firstName
}

// ��^�m
string CommissionEmployee::getLastName() const {
    return lastName; // ��^ lastName
}

// ��^���|�w�����X
string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber; // ��^ socialSecurityNumber
}
