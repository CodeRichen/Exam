#include <iostream>
using namespace std;
class A {
public:
    virtual void show() { cout << "A::show()" << endl; }
    // void show2() { cout << "A::show2()" << endl; }
};

class B : public A {
public:
    void show(){ cout << "B::show()" << endl; }
    void show2() { cout << "B::show2()" << endl; }
};

class C : public B {
public:
    void show() { cout << "C::show()" << endl; }
};

int main() {
    A* aPtr;
    A* aPtr2;
    C* cPtr;
    C cObj;
    A aObj;
    aPtr = &cObj;
    aPtr->show(); // ?�� C::show()
    aPtr2 = &aObj;
    aPtr2->show();
    cPtr = &cObj;
    cout<<"-----------"<<endl;
    cPtr->show(); // ?�� C::show()
    cPtr->show2(); // ?�� B::show2()
    // aObj.show2();
    cObj.show();
    cObj.show2();
    A a();
    C* cPtr2=new C();
    cPtr2->show();
    return 0;
}
