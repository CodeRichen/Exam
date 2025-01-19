// CommissionEmployee.h
#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include <string>
using namespace std;

class CommissionEmployee {
public:
    // �c�y���
    CommissionEmployee(const string&, const string&, const string&,
        double = 0.0, double = 0.0);

    void setFirstName(const string&);
    string getFirstName() const;

    void setLastName(const string&);
    string getLastName() const;

    void setSocialSecurityNumber(const string&);
    string getSocialSecurityNumber() const;

    void setGrossSales(double); // �]�m�`�P���B
    double getGrossSales() const; // ����`�P���B

    void setCommissionRate(double); // �]�m�����v
    double getCommissionRate() const; // ��������v

    double earnings() const; // �p�⦬�J
    void print() const;      // ���L�H��

protected:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales;
    double commissionRate;
};

#endif
