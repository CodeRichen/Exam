// BasePlusCommissionEmployee.h
#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H
#define BASEPLUSCOMMISSIONEMPLOYEE_H

#include "CommissionEmployee.h" // �~�� CommissionEmployee ��

class BasePlusCommissionEmployee : public CommissionEmployee {
public:
    // �c�y��ơA���F�������ݩʥ~�W�[�F��¦�~��
    BasePlusCommissionEmployee(const string&, const string&, const string&,
        double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double); // �]�m��¦�~��
    double getBaseSalary() const; // �����¦�~��

    // �л\ earnings ���
    double earnings() const;

    // �л\ print ��ơA�K�[��¦�~��H��
    void print() const;

private:
    double baseSalary; // ��¦�~��
};

#endif
