#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
using namespace std;


class Package {
protected:
    string senderName;
    string senderAddress;
    string senderCity;
    string senderState;
    string senderZip;
    string recipientName;
    string recipientAddress;
    string recipientCity;
    string recipientState;
    string recipientZip;

    double weight;        
    double costPerOunce;  

public:
    
    Package(const string& senderName, const string& senderAddress, const string& senderCity,
        const string& senderState, const string& senderZip, const string& recipientName,
        const string& recipientAddress, const string& recipientCity, const string& recipientState,
        const string& recipientZip, double weight, double costPerOunce);

    
    virtual double calculateCost() const;
    virtual void print() const;
    
    virtual ~Package() {}
};


class TwoDayPackage : public Package {
private:
    double flatFee;  

public:

    TwoDayPackage(const string& senderName, const string& senderAddress, const string& senderCity,
        const string& senderState, const string& senderZip, const string& recipientName,
        const string& recipientAddress, const string& recipientCity, const string& recipientState,
        const string& recipientZip, double weight, double costPerOunce, double flatFee);

    virtual void print() const;
    double calculateCost() const override;
};


class OvernightPackage : public Package {
private:
    double extraCostPerOunce;  

public:

    OvernightPackage(const string& senderName, const string& senderAddress, const string& senderCity,
        const string& senderState, const string& senderZip, const string& recipientName,
        const string& recipientAddress, const string& recipientCity, const string& recipientState,
        const string& recipientZip, double weight, double costPerOunce, double extraCostPerOunce);

    virtual void print() const;
    double calculateCost() const override;
};

#endif
