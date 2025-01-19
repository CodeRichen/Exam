#include <iostream>
#include "CommissionEmployee.h"
using namespace std;

CommissionEmployee::CommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate)
    : firstName(first), lastName(last), socialSecurityNumber(ssn), grossSales(sales), commissionRate(rate) {}

void CommissionEmployee::setFirstName(const string& first) {
    firstName = first;
}

string CommissionEmployee::getFirstName() const {
    return firstName;
}

void CommissionEmployee::setLastName(const string& last) {
    lastName = last;
}

string CommissionEmployee::getLastName() const {
    return lastName;
}

void CommissionEmployee::setSocialSecurityNumber(const string& ssn) {
    socialSecurityNumber = ssn;
}

string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}

void CommissionEmployee::setGrossSales(double sales) {
    grossSales = sales;
}

double CommissionEmployee::getGrossSales() const {
    return grossSales;
}

void CommissionEmployee::setCommissionRate(double rate) {
    commissionRate = rate;
}

double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

double CommissionEmployee::earnings() const {
    return commissionRate * grossSales;
}

void CommissionEmployee::print() const {
    cout << "Commission employee: " << firstName << ' ' << lastName
        << "\nSocial security number: " << socialSecurityNumber
        << "\nGross sales: " << grossSales
        << "\nCommission rate: " << commissionRate;
}
