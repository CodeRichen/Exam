#include <iostream>
#include <string>
using namespace std;
class Abstract {
public:
    virtual void pureVirtualFunction() = 0;
    // void p() {cout<<1;}
    virtual ~Abstract() {
        cout << "Abstract class destructor called." << endl;
    }
};
class Derived : public Abstract {
public:
    void pureVirtualFunction() override {
        cout << "Implementing pure virtual function." << endl;
    }
};
int main() {
    // Abstract obj; // 错误：不能实例化抽象类
    Derived obj;
    obj.pureVirtualFunction();
    return 0;
}
