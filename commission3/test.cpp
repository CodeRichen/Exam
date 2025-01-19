#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include "SalaryEmployee1.h" 

using namespace std;

void virtualViaPointer(const Employee * const); 
void virtualViaReference(const Employee &); 

int main() {
    cout << fixed << setprecision(2);

    // create derived-class objects
    SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", 800);
    CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", 10000, .06);
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", 5000, .04, 300);
    SalaryEmployee1 salaryEmployee1("Alice", "Brown", "555-55-5555", 3000); 

    cout << "Employees processed individually using static binding:\n\n";

    salariedEmployee.print();
    cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";

    commissionEmployee.print();
    cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";

    basePlusCommissionEmployee.print();
    cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

    salaryEmployee1.print();
    cout << "\nearned $" << salaryEmployee1.earnings() << "\n\n";

    cout << "Employees processed polymorphically via dynamic binding:\n\n";

    
    vector<Employee *> employees(4);
    employees[0] = &salariedEmployee;
    employees[1] = &commissionEmployee;
    employees[2] = &basePlusCommissionEmployee;
    employees[3] = &salaryEmployee1; 

    for (const Employee *employeePtr : employees)
        virtualViaPointer(employeePtr);//直接傳指針過去指別人


    for (const Employee *employeePtr : employees)
        virtualViaReference(*employeePtr);//將地址船過去

    return 0;
}

void virtualViaPointer(const Employee * const baseClassPtr) {
    baseClassPtr->print();
    cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}

void virtualViaReference(const Employee &baseClassRef) {
    baseClassRef.print();
    cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
}
