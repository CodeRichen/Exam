#include "Package.h"
#include <iostream>
using namespace std;

int main() {


        Package basePackage("Richen", "123 Main St", "Townsville", "TS", "12345",
            "Bob", "456 Elm St", "Cityville", "CV", "67890", 5.0, 2.0);
        cout << "Basic Package:" << endl;
        basePackage.print();

        TwoDayPackage twoDayPackage("miku", "123 Main St", "Townsville", "TS", "12345",
            "Bob", "456 Elm St", "Cityville", "CV", "67890", 9.0, 3.0, 10.0);
        cout << "twoDayPackage:" << endl;
        twoDayPackage.print();

        OvernightPackage overnightPackage("Alice", "123 Main St", "Townsville", "TS", "12345",
            "Bob", "456 Elm St", "Cityville", "CV", "67890", 5.0, 4.0, 1.5);
        cout << "overnightPackage:" << endl;
        overnightPackage.print();


    return 0;
}
