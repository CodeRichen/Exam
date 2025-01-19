#ifndef SALARIED_H
#define SALARIED_H

#include <string>
#include "Employee.h"

class SalariedEmployee : public Employee {
public:
    SalariedEmployee(const std::string &, const std::string &, const std::string &, double = 0.0);
    virtual ~SalariedEmployee() { } // virtual destructor

    void setWeeklySalary(double); // set weekly salary
    double getWeeklySalary() const; // return weekly salary

    // override pure virtual functions
    virtual double earnings() const override;
    virtual void print() const override;

private:
    double weeklySalary; // weekly salary
};

#endif // SALARIED_H
