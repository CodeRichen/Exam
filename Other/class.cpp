#include <iostream>
using namespace std;

class ClassA {
public:
    void show() {
        cout << "ClassA show()" << endl;
    }
};

class ClassB {
public:
    void show() {
        cout << "ClassB show()" << endl;
    }
};

class Derived : public ClassA, public ClassB {
public:
   
};

int main() {
    Derived d;

    // 编译器无法判断调用哪个 show()，会报错
    d.show(); // Error: ambiguous
    return 0;
}
