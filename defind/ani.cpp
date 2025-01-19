#include<iostream>
using namespace std;
class Animal {
public:
    void dosomething() {
         cout << "Animal is doing something." <<  endl;
    }
    virtual void dosomething2() {
         cout << "Animal is doing something2." <<  endl;
    }
};

class Fish : public Animal {
public:
    void dosomething()  {
         cout << "Fish is swimming." <<  endl;
    }
    void dosomething2() override {
         cout << "Fish is swimming2." <<  endl;
    }
};

int main() {
    Animal* jack = new Fish;
    Animal generalAnimal;    
    Fish specificFish;    
    cout << "=== Redefined Function ===" << endl;
    generalAnimal.dosomething();   
    specificFish.dosomething();    
    jack->dosomething();
    cout << "\n=== Overridden Function ===" << endl;
    generalAnimal.dosomething2();
    specificFish.dosomething2();
    jack->dosomething2();
    delete jack;
    return 0;
}
