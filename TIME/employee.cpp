#include <iostream>
#include "Employee.h"
#include "Date.h"
using namespace std;

Employee::Employee(const string& first, const string& last, const Date& dateOfBirth, const Date& dateOfHire ,const Date& leavesDate)
    : firstName(first), lastName(last), birthDate(dateOfBirth), hireDate(dateOfHire), leaveDate(leavesDate){
    cout << "Employee object constructor: " << firstName << ' ' << lastName << endl;
}

void Employee::print() const {
    cout << lastName << ", " << firstName << " Hired: ";
    hireDate.print();
    cout << " Birthday: ";
    birthDate.print();
    cout << " leaveDate: ";
    leaveDate.print();
    cout << endl;
}

Employee::~Employee() {
    cout << "Employee object destructor: " << lastName << ", " << firstName << endl;
}
