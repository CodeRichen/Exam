
#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
public:
    virtual ~Base() {} // 必須有虛函數才能使用 dynamic_cast
};

class Derived : public Base {};
class AnotherClass : public Base {};

int main() {
    Base* basePtr = new Derived();          // 動態類型是 Derived
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        cout << "Successfully cast to Derived!" << endl; // 轉型成功
    } else {
        cout << "Failed to cast to Derived!" << endl;
    }

    Base* anotherPtr = new AnotherClass();  // 動態類型是 AnotherClass
    Derived* invalidCast = dynamic_cast<Derived*>(anotherPtr);
    if (invalidCast) {
        cout << "Successfully cast to Derived!" << endl;
    } else {
        cout << "Failed to cast to Derived!" << endl;   // 轉型失敗
    }

    delete basePtr;
    delete anotherPtr;
    return 0;
}
