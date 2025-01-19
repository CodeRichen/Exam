// Fig. 19.9: fig19_09.cpp
// ���� BasePlusCommissionEmployee ���O
#include <iostream>
#include <iomanip>
#include "BasePlusCommissionEmployee.h"
using namespace std;

int main() {
    // ��Ҥ� BasePlusCommissionEmployee ��H
    BasePlusCommissionEmployee employee(
        "Bob", "Lewis", "333-33-3333", 5000, .04, 300);

    // �]�m�B�I�ƿ�X�榡
    cout << fixed << setprecision(2);

    // �ϥ� get ��ƿ�X���u�H��
    cout << "Employee information obtained by get functions: \n"
        << "\nFirst name is " << employee.getFirstName()
        << "\nLast name is " << employee.getLastName()
        << "\nSocial security number is " << employee.getSocialSecurityNumber()
        << "\nGross sales is " << employee.getGrossSales()
        << "\nCommission rate is " << employee.getCommissionRate()
        << "\nBase salary is " << employee.getBaseSalary() << endl;

    // ��s��¦�~��
    employee.setBaseSalary(2000); // �]�m��¦�~�ꬰ 2000

    // �ϥ� print ��ƿ�X��s�᪺���u�H��
    cout << "\nUpdated employee information output by print function: \n" << endl;
    employee.print(); // ��ܷs�����u�H��

    // ��X���u���J
    cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;
} // end main
