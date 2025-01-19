// BasePlusCommissionEmployee.h
// BasePlusCommissionEmployee ���O�w�q�A�q CommissionEmployee �l�ͦӨӡC
#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string> // C++ �зǦr�����O
#include "CommissionEmployee.h" // �ޤJ CommissionEmployee ���O�w�q
using namespace std;

// BasePlusCommissionEmployee ���O�w�q
class BasePlusCommissionEmployee : public CommissionEmployee {
public:
    // �غc��ơA��l�ư����O�M���~
    BasePlusCommissionEmployee(const string&, const string&,
        const string&, double = 0.0, double = 0.0, double = 0.0);
    ~BasePlusCommissionEmployee(); // �Ѻc���

    // �]�w�M������~���������
    void setBaseSalary(double); // �]�w���~
    double getBaseSalary() const; // ��^���~

    double earnings() const; // �p�⦬�J
    void print() const; // �C�L BasePlusCommissionEmployee ��H����T

private:
    double baseSalary; // ���~
}; // end class BasePlusCommissionEmployee

#endif // BASEPLUS_H
