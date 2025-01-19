#ifndef SALARYEMPLOYEE1_H
#define SALARYEMPLOYEE1_H

#include <string>
#include "Employee.h"

class SalaryEmployee1 : public Employee {
public:
    SalaryEmployee1(const std::string &, const std::string &, const std::string &, double = 0.0);
    virtual ~SalaryEmployee1() { } 

    void setMonthlySalary(double); 
    double getMonthlySalary() const; 

   
    virtual double earnings() const override;
    virtual void print() const override;

private:
    double monthlySalary; 
};

#endif 
