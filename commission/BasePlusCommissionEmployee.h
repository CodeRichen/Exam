// BasePlusCommissionEmployee.h
#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H
#define BASEPLUSCOMMISSIONEMPLOYEE_H

#include "CommissionEmployee.h" // 繼承 CommissionEmployee 類

class BasePlusCommissionEmployee : public CommissionEmployee {
public:
    // 構造函數，除了基類的屬性外增加了基礎薪資
    BasePlusCommissionEmployee(const string&, const string&, const string&,
        double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double); // 設置基礎薪資
    double getBaseSalary() const; // 獲取基礎薪資

    // 覆蓋 earnings 函數
    double earnings() const;

    // 覆蓋 print 函數，添加基礎薪資信息
    void print() const;

private:
    double baseSalary; // 基礎薪資
};

#endif
