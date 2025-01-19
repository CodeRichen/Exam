// Fig. 19.9: fig19_09.cpp
// 測試 BasePlusCommissionEmployee 類別
#include <iostream>
#include <iomanip>
#include "BasePlusCommissionEmployee.h"
using namespace std;

int main() {
    // 實例化 BasePlusCommissionEmployee 對象
    BasePlusCommissionEmployee employee(
        "Bob", "Lewis", "333-33-3333", 5000, .04, 300);

    // 設置浮點數輸出格式
    cout << fixed << setprecision(2);

    // 使用 get 函數輸出員工信息
    cout << "Employee information obtained by get functions: \n"
        << "\nFirst name is " << employee.getFirstName()
        << "\nLast name is " << employee.getLastName()
        << "\nSocial security number is " << employee.getSocialSecurityNumber()
        << "\nGross sales is " << employee.getGrossSales()
        << "\nCommission rate is " << employee.getCommissionRate()
        << "\nBase salary is " << employee.getBaseSalary() << endl;

    // 更新基礎薪資
    employee.setBaseSalary(2000); // 設置基礎薪資為 2000

    // 使用 print 函數輸出更新後的員工信息
    cout << "\nUpdated employee information output by print function: \n" << endl;
    employee.print(); // 顯示新的員工信息

    // 輸出員工收入
    cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;
} // end main
