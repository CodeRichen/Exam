#include <iostream>
using namespace std;

class Base {
public:
    Base() { std::cout << "Base constructor" << std::endl; }
    virtual ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor" << std::endl; }
    ~Derived() { std::cout << "Derived destructor" << std::endl; }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;  // �p�GBase���Ѻc�禡���O���ơA�h�u�|�ե�Base���Ѻc�禡�ADerived���Ѻc�禡���|�Q�ե�

    return 0;
}