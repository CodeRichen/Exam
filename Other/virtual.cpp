#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() {
        std::cout << "Base display" << std::endl;
    }
    virtual ~Base() {std::cout << "Base" << std::endl;}
};

class Derived : public Base {
public:
    void display() override {
        std::cout << "Derived display" << std::endl;
    }
    ~Derived() {std::cout << "Derived" << std::endl;
    std::cout.flush(); // 刷新缓冲区，避免输出不完整
    }
    
};

int main() {
    Base* obj = new Derived();
    obj->display(); // 輸出 "Derived display"
    delete obj; // 釋放動態分配的記憶體
    // std::cin.get(); // 等待用户
    return 0;
}