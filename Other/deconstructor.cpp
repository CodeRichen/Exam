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
    delete ptr;  // 如果Base的解構函式不是虛函數，則只會調用Base的解構函式，Derived的解構函式不會被調用

    return 0;
}