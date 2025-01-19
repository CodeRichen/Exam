#include <iostream>
using namespace std;

class Base {
public:
    void publicMethod() {
        cout << "Base public method called." << endl;
    }

protected:
    void protectedMethod() {
        cout << "Base protected method called." << endl;
    }

private:
    void privateMethod() {
        cout << "Base private method called." << endl;
    }
};

class PublicDerived : public Base {
public:
    void testAccess() {
        publicMethod();    // 繼承的 public 成員：保持 public
        protectedMethod(); // 繼承的 protected 成員：保持 protected
        // privateMethod(); // 無法訪問 private 成員
    }
};

class ProtectedDerived : protected Base {
public:
    void testAccess() {
        publicMethod();    // 繼承的 public 成員：變成 protected
        protectedMethod(); // 繼承的 protected 成員：保持 protected
        // privateMethod(); // 無法訪問 private 成員
    }
};

class PrivateDerived : private Base {
public:
    void testAccess() {
        publicMethod();    // 繼承的 public 成員：變成 private
        protectedMethod(); // 繼承的 protected 成員：變成 private
        // privateMethod(); // 無法訪問 private 成員
    }
};

int main() {
    // PublicDerived 測試
    PublicDerived publicObj;
    publicObj.publicMethod(); // 公開方法，從基類繼承，仍可直接訪問
    // publicObj.protectedMethod(); // 無法訪問 protected 方法
    publicObj.testAccess(); // 測試從子類訪問

    cout << "-------------------------------------" << endl;

    // ProtectedDerived 測試
    ProtectedDerived protectedObj;
    // protectedObj.publicMethod(); // 無法訪問，變成 protected
    protectedObj.testAccess(); // 測試從子類訪問

    cout << "-------------------------------------" << endl;

    // PrivateDerived 測試
    PrivateDerived privateObj;
    // privateObj.publicMethod(); // 無法訪問，變成 private
    privateObj.testAccess(); // 測試從子類訪問

    return 0;
}
