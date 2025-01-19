#include "Package.h"
#include <stdexcept>
#include <iostream>
using namespace std;


Package::Package(const string& senderName, const string& senderAddress, const string& senderCity,
    const string& senderState, const string& senderZip, const string& recipientName,
    const string& recipientAddress, const string& recipientCity, const string& recipientState,
    const string& recipientZip, double weight, double costPerOunce)
    : senderName(senderName), senderAddress(senderAddress), senderCity(senderCity),
    senderState(senderState), senderZip(senderZip), recipientName(recipientName),
    recipientAddress(recipientAddress), recipientCity(recipientCity), recipientState(recipientState),
    recipientZip(recipientZip), weight(weight), costPerOunce(costPerOunce) {
    if (weight <= 0 || costPerOunce <= 0) {
        throw invalid_argument("Weight and cost per ounce must be positive.");
    }
}


double Package::calculateCost() const {
    return weight * costPerOunce;
}
void Package::print() const {
    cout << "Sender: " << senderName << ", " << senderAddress << ", " << senderCity << ", "
        << senderState << ", " << senderZip << endl;
    cout << "Recipient: " << recipientName << ", " << recipientAddress << ", " << recipientCity << ", "
        << recipientState << ", " << recipientZip << endl;
    cout << "Weight: " << weight << " ounces, Cost per ounce: $" << costPerOunce << endl;
}

TwoDayPackage::TwoDayPackage(const string& senderName, const string& senderAddress, const string& senderCity,
    const string& senderState, const string& senderZip, const string& recipientName,
    const string& recipientAddress, const string& recipientCity, const string& recipientState,
    const string& recipientZip, double weight, double costPerOunce, double flatFee)
    : Package(senderName, senderAddress, senderCity, senderState, senderZip, recipientName,
        recipientAddress, recipientCity, recipientState, recipientZip, weight, costPerOunce),
    flatFee(flatFee) {
    if (flatFee < 0) {
        throw invalid_argument("Flat fee must be non-negative.");
    }
}


double TwoDayPackage::calculateCost() const {
    return Package::calculateCost() + flatFee;
}
void TwoDayPackage::print() const  {
    Package::print();
    cout << "Flat fee: $TwoDayPackage Package cost : $" << calculateCost() << endl;
}

OvernightPackage::OvernightPackage(const string& senderName, const string& senderAddress, const string& senderCity,
    const string& senderState, const string& senderZip, const string& recipientName,
    const string& recipientAddress, const string& recipientCity, const string& recipientState,
    const string& recipientZip, double weight, double costPerOunce, double extraCostPerOunce)
    : Package(senderName, senderAddress, senderCity, senderState, senderZip, recipientName,
        recipientAddress, recipientCity, recipientState, recipientZip, weight, costPerOunce),
    extraCostPerOunce(extraCostPerOunce) {
    if (extraCostPerOunce < 0) {
        throw invalid_argument("Extra cost per ounce must be non-negative.");
    }
}

double OvernightPackage::calculateCost() const {
    return weight * (costPerOunce + extraCostPerOunce);
}
void OvernightPackage::print() const  {
    Package::print();
    cout << "Flat fee: $Overnight Package cost : $" << calculateCost() << endl;
}
