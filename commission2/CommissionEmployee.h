// CommissionEmployee.h
// CommissionEmployee 類別定義，代表一名佣金員工。
#ifndef COMMISSION_H
#define COMMISSION_H

#include <string> // C++ 標準字串類別
using namespace std;

// CommissionEmployee 類別定義
class CommissionEmployee {
public:
    // 建構函數，初始化員工的名字、社會安全號碼、銷售額和佣金率
    CommissionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);
    ~CommissionEmployee(); // 解構函數

    // 設定和獲取名子的成員函數
    void setFirstName(const string&); // 設定名子
    string getFirstName() const; // 返回名子

    void setLastName(const string&); // 設定姓氏
    string getLastName() const; // 返回姓氏

    void setSocialSecurityNumber(const string&); // 設定社會安全號碼
    string getSocialSecurityNumber() const; // 返回社會安全號碼

    void setGrossSales(double); // 設定總銷售額
    double getGrossSales() const; // 返回總銷售額

    void setCommissionRate(double); // 設定佣金率
    double getCommissionRate() const; // 返回佣金率
    double earnings() const; // 新增：計算收入
    void print() const; // 新增：列印函數

private:
    string firstName; // 名子
    string lastName; // 姓氏
    string socialSecurityNumber; // 社會安全號碼
    double grossSales; // 總銷售額
    double commissionRate; // 佣金率
}; // end class CommissionEmployee

#endif // COMMISSION_H
