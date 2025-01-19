#include <iostream>
#include <typeinfo>
using namespace std;
class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};
class AnotherDerived : public Base {};
int main() {
    int a = 10;
    double b = 5.5;
    string c = "H";
    char d = 'c';
    const type_info& typeA = typeid(a);
    const type_info& typeB = typeid(b);
    const type_info& typeC = typeid(c);
    const type_info& typeD = typeid(d);
    cout << "a : " << typeA.name() << endl;
    cout << "b : " << typeB.name() << endl;
    cout << "c : " << typeC.name() << endl;
    cout << "d : " << typeD.name() << endl;
    // Base* basePtr = new Derived();
    Base* basePtr = new Base();
    if (typeid(*basePtr) == typeid(Derived)) {
        cout << " Derived" << endl;
        Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
        if (derivedPtr) {
            cout << "c Derived " << endl;
        }
    } else {
        cout << "n Derived " << endl;
    }

    delete basePtr;
    return 0;
}
