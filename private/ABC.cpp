#include <iostream>
using namespace std;

class C {
protected:
    int protectedValue;
public:
    C() : protectedValue(42) {}
    void showValue() {
        cout << "Protected Value: " << protectedValue << endl;
    }
};

class B : public C {
public:
    void modifyValue(int newValue) {
        protectedValue = newValue; // 訪問 C 的受保護成員
    }
};

class A : public B {
public:
    void useValue() {
        cout << "Using C's protected value: " << protectedValue << endl; // 訪問 C 的受保護成員
    }
};

int main() {
    A objA;
    objA.showValue();  // 呼叫來自 C 的公共成員函數
    objA.modifyValue(100); // 呼叫來自 B 的公共函數修改 C 的成員
    objA.useValue();   // 使用來自 C 的受保護成員
    return 0;
}
