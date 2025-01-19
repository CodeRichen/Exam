#include <iostream>
#include "BasePlusCommissionEmployee.h"
using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, sales, rate) {
    setBaseSalary(salary);
    cout << "BasePlusCommissionEmployee constructor: " << endl;
    print();
    cout << "\n\n";
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee() {
    cout << "BasePlusCommissionEmployee destructor: " << endl;
    print();
    cout << "\n\n";
}

// �]�w���~��
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = (salary < 0.0) ? 0.0 : salary;
}

// ��^���~��
double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

// �p���`���J
double BasePlusCommissionEmployee::earnings() const {
    return getBaseSalary() + CommissionEmployee::earnings();
}

// �C�L BasePlusCommissionEmployee ��T
void BasePlusCommissionEmployee::print() const {
    cout << "base-salaried ";
    CommissionEmployee::print(); // �եΰ����� print ���
    cout << "base salary: " << getBaseSalary() << "\n";
}
