#ifndef COMMISSION_H
#define COMMISSION_H

#include <string>
#include "Employee.h"

class CommissionEmployee : public Employee {
public:
    CommissionEmployee(const std::string &, const std::string &, const std::string &, double = 0.0, double = 0.0);
    virtual ~CommissionEmployee() { } // virtual destructor

    void setGrossSales(double); // set gross sales amount
    double getGrossSales() const; // return gross sales amount

    void setCommissionRate(double); // set commission rate
    double getCommissionRate() const; // return commission rate

    virtual double earnings() const override;
    virtual void print() const override;

private:
    double grossSales; // gross weekly sales
    double commissionRate; // commission percentage
};

#endif // COMMISSION_H
