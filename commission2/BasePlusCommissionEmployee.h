// BasePlusCommissionEmployee.h
// BasePlusCommissionEmployee 類別定義，從 CommissionEmployee 衍生而來。
#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string> // C++ 標準字串類別
#include "CommissionEmployee.h" // 引入 CommissionEmployee 類別定義
using namespace std;

// BasePlusCommissionEmployee 類別定義
class BasePlusCommissionEmployee : public CommissionEmployee {
public:
    // 建構函數，初始化基底類別和底薪
    BasePlusCommissionEmployee(const string&, const string&,
        const string&, double = 0.0, double = 0.0, double = 0.0);
    ~BasePlusCommissionEmployee(); // 解構函數

    // 設定和獲取底薪的成員函數
    void setBaseSalary(double); // 設定底薪
    double getBaseSalary() const; // 返回底薪

    double earnings() const; // 計算收入
    void print() const; // 列印 BasePlusCommissionEmployee 對象的資訊

private:
    double baseSalary; // 底薪
}; // end class BasePlusCommissionEmployee

#endif // BASEPLUS_H
