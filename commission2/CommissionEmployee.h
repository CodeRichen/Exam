// CommissionEmployee.h
// CommissionEmployee ���O�w�q�A�N��@�W�������u�C
#ifndef COMMISSION_H
#define COMMISSION_H

#include <string> // C++ �зǦr�����O
using namespace std;

// CommissionEmployee ���O�w�q
class CommissionEmployee {
public:
    // �غc��ơA��l�ƭ��u���W�r�B���|�w�����X�B�P���B�M�����v
    CommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);
    ~CommissionEmployee(); // �Ѻc���

    // �]�w�M����W�l���������
    void setFirstName(const string&); // �]�w�W�l
    string getFirstName() const; // ��^�W�l

    void setLastName(const string&); // �]�w�m��
    string getLastName() const; // ��^�m��

    void setSocialSecurityNumber(const string&); // �]�w���|�w�����X
    string getSocialSecurityNumber() const; // ��^���|�w�����X

    void setGrossSales(double); // �]�w�`�P���B
    double getGrossSales() const; // ��^�`�P���B

    void setCommissionRate(double); // �]�w�����v
    double getCommissionRate() const; // ��^�����v
    double earnings() const; // �s�W�G�p�⦬�J
    void print() const; // �s�W�G�C�L���

private:
    string firstName; // �W�l
    string lastName; // �m��
    string socialSecurityNumber; // ���|�w�����X
    double grossSales; // �`�P���B
    double commissionRate; // �����v
}; // end class CommissionEmployee

#endif // COMMISSION_H
