// CommissionEmployee.h
#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include <string>
using namespace std;

class CommissionEmployee {
public:
    // 構造函數
    CommissionEmployee(const string&, const string&, const string&,
        double = 0.0, double = 0.0);

    void setFirstName(const string&);
    string getFirstName() const;

    void setLastName(const string&);
    string getLastName() const;

    void setSocialSecurityNumber(const string&);
    string getSocialSecurityNumber() const;

    void setGrossSales(double); // 設置總銷售額
    double getGrossSales() const; // 獲取總銷售額

    void setCommissionRate(double); // 設置佣金率
    double getCommissionRate() const; // 獲取佣金率

    double earnings() const; // 計算收入
    void print() const;      // 打印信息

protected:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    double grossSales;
    double commissionRate;
};

#endif
