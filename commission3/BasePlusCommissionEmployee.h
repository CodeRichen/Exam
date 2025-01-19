#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee {
public:
    BasePlusCommissionEmployee(const std::string &, const std::string &, const std::string &, double = 0.0, double = 0.0, double = 0.0);
    virtual ~BasePlusCommissionEmployee() { }

    void setBaseSalary(double); // set base salary
    double getBaseSalary() const; // return base salary

    virtual double earnings() const override;
    virtual void print() const override;

private:
    double baseSalary; // base salary per week
};

#endif // BASEPLUS_H
