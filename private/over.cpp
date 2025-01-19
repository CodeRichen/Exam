#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {  // 虛函數
        cout << "1" << endl;
    }
    virtual ~Animal() {}  // 虛析構函數，避免資源洩漏
};

class Dog : public Animal {
public:
    void sound() override {  // 覆寫
        cout << "2" << endl;
    }
};

int main() {
    Dog* animalPtr = new Dog;
    animalPtr->sound();  
    delete animalPtr;
    return 0;
}
