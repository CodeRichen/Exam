#include <iostream>
#include <typeinfo>
using namespace std;

class Bases {
public:
    virtual ~Bases() {} 
};

class Derived : public Bases {};

int main() {
    Bases* basePtr0 = new Bases();
    cout << "basePtr0:" << typeid(*basePtr0).name() << endl;

    Bases* basePtr = new Derived();
    cout << "basePtr:" << typeid(*basePtr).name() << endl;

    Bases baseObj;
    cout << "baseObj:" << typeid(baseObj).name() << endl;

    Bases& baseRef = baseObj;
    cout << "baseRef:" << typeid(baseRef).name() << endl;

    Bases* basePtr2 = &baseObj;
    cout << "basePtr2:" << typeid(*basePtr2).name() << endl;

    Derived derivedObj;
    Bases* basePtr3 = &derivedObj;
    cout << "basePtr3:" << typeid(*basePtr3).name() << endl;
    cout << "derivedObj:" << typeid(derivedObj).name() << endl;
    delete basePtr;
    return 0;
}
// typeid 的行為依賴於指針或引用所指向物件的動態類型，
// 但只有在有虛函數的類型，且物件通過多態（指針或引用）操作時，才能正確反映物件的動態類型。

// 動態類型：物件在執行時的真實類型（例如，Derived）。
// 靜態類型：物件在編譯時由變數定義決定的類型（例如，Base）。

// typeid 行為：
// 用於靜態類型（非指針）時，僅返回靜態類型名稱。
// 用於指針（含虛函數）時，可檢測實際對象的類型名稱。

// 7Derived 表示類型名稱為 Derived，長度為 7
// 4Base 表示類型名稱為 Base，長度為 4

// 多態的核心概念是 通過基類指針或引用操作派生類對象，這樣可以實現不同的行為。
// 而當我們直接創建對象時，不涉及指針或引用，行為由對象的靜態類型決定。

