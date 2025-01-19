#include <iostream>
#include <stdexcept>
#include "CommissionEmployee.h"
using namespace std;

// constructor
CommissionEmployee::CommissionEmployee(const string &first, const string &last, const string &ssn, double sales, double rate)
    : Employee(first, last, ssn) {
    setGrossSales(sales);
    setCommissionRate(rate);
}

// set gross sales amount
void CommissionEmployee::setGrossSales(double sales) {
    if (sales >= 0.0)
        grossSales = sales;
    else
        throw invalid_argument("Gross sales must be >= 0.0");
}

// return gross sales amount
double CommissionEmployee::getGrossSales() const {
    return grossSales;
}

// set commission rate
void CommissionEmployee::setCommissionRate(double rate) {
    if (rate > 0.0 && rate < 1.0)
        commissionRate = rate;
    else
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
}

// return commission rate
double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

// calculate earnings
double CommissionEmployee::earnings() const {
    return getCommissionRate() * getGrossSales();
}

// print CommissionEmployee's information
void CommissionEmployee::print() const {
    cout << "commission employee: ";
    Employee::print();
    cout << "\ngross sales: " << getGrossSales()
         << "; commission rate: " << getCommissionRate();
}
