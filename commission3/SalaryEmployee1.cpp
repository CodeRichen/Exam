#include <iostream>
#include <stdexcept>
#include "SalaryEmployee1.h"
using namespace std;


SalaryEmployee1::SalaryEmployee1(const string &first, const string &last, const string &ssn, double salary)
    : Employee(first, last, ssn) {
    setMonthlySalary(salary);
}


void SalaryEmployee1::setMonthlySalary(double salary) {
    if (salary >= 0.0)
        monthlySalary = salary;
    else
        throw invalid_argument("Monthly salary must be >= 0.0");
}


double SalaryEmployee1::getMonthlySalary() const {
    return monthlySalary;
}

double SalaryEmployee1::earnings() const {
    return getMonthlySalary();
}


void SalaryEmployee1::print() const {
    cout << "monthly-salaried employee: ";
    Employee::print(); 
    cout << "\nmonthly salary: " << getMonthlySalary();
}
