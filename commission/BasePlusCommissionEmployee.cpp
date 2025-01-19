#include <iostream>
#include "BasePlusCommissionEmployee.h"
using namespace std;

// 构造函数，调用基类构造函数并初始化 baseSalary
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& first, const string& last, const string& ssn,
    double sales, double rate, double salary)
    : CommissionEmployee(first, last, ssn, sales, rate) // 調用基類構造函數
{
    setBaseSalary(salary); // 設置 baseSalary
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = (salary < 0.0) ? 0.0 : salary;
}

double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const {
    // 總收入 = 基礎薪資 + 基類計算的佣金收入
    return baseSalary + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const {
    cout << "base-salaried ";
    CommissionEmployee::print(); // 調用基類的 print 函數
    cout << "\nbase salary: " << baseSalary;
}
