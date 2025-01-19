#include <iostream>
#include <string>
using namespace std;

// 抽象類別
class Animal {
protected:
    string name;

public:
    // 建構函數
    Animal(const string& animalName) : name(animalName) {}

    // 純虛函數
    virtual void sound() const = 0;

    // 具體函數
    void showInfo() const {
        cout << "動物名稱: " << name << endl;
    }

    // 虛擬解構函數
    virtual ~Animal() {}
};

// 衍生類
class Dog : public Animal {
public:
    Dog(const string& dogName) : Animal(dogName) {}

    // 實作純虛函數
    void sound() const override {
        cout << name << " 叫聲: 汪汪" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(const string& catName) : Animal(catName) {}

    // 實作純虛函數
    void sound() const override {
        cout << name << " 叫聲: 喵喵" << endl;
    }
};

int main() {
    // Animal animal("Animal"); // 錯誤：無法實例化抽象類別

    Animal* dog = new Dog("Lucky");
    Animal* cat = new Cat("Kitty");

    dog->showInfo(); // 呼叫具體函數
    dog->sound();    // 呼叫覆寫的純虛函數

    cat->showInfo(); // 呼叫具體函數
    cat->sound();    // 呼叫覆寫的純虛函數

    delete dog;
    delete cat;

    return 0;
}
