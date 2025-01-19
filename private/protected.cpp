#include <iostream>
using namespace std;

class Base {
public:
    int publicVar = 1;

protected:
    int protectedVar = 2;

private:
    int privateVar = 3; // 无法被继承
};

// 使用 protected 继承
class ProtectedDerived : protected Base {
public:
    void showMembers() {
        cout << "Accessing Base members in ProtectedDerived:" << endl;
        cout << "publicVar: " << publicVar << endl;
        cout << "protectedVar: " << protectedVar << endl;
        // cout << privateVar; // 错误：无法访问 Base 的 private 成员
    }
};

// 使用 private 继承
class PrivateDerived : private Base {
public:
    void showMembers() {
        cout << "Accessing Base members in PrivateDerived:" << endl;
        cout << "publicVar: " << publicVar << endl;
        cout << "protectedVar: " << protectedVar << endl;
        // cout << privateVar; // 错误：无法访问 Base 的 private 成员
    }
};

// 进一步派生类尝试访问成员
class SubProtectedDerived : public ProtectedDerived {
public:
    void accessBaseMembers() {
        // 可以访问 protected 的 publicVar 和 protectedVar
        cout << "SubProtectedDerived accessing Base members:" << endl;
        cout << "publicVar: " << publicVar << endl;
        // cout << publicVar; // 错误：被 ProtectedDerived 设置为 protected
        // cout << protectedVar; // 错误：被 ProtectedDerived 设置为 protected
    }
};

class SubPrivateDerived : public PrivateDerived {
public:
    void accessBaseMembers() {
        // 无法访问任何 Base 的成员
        cout << "SubPrivateDerived cannot access Base members." << endl;
        // cout << "publicVar: " << publicVar << endl;  這一行不行被執行
        // cout << publicVar; // 错误：被 PrivateDerived 设置为 private
        // cout << protectedVar; // 错误：被 PrivateDerived 设置为 private
    }
};

int main() {
    ProtectedDerived pd;
    pd.showMembers();
    // cout << pd.publicVar; // 错误：Base 的 public 成员变为 protected

    PrivateDerived prd;
    prd.showMembers();
    // cout << prd.publicVar; // 错误：Base 的 public 成员变为 private

    SubProtectedDerived spd;
    spd.accessBaseMembers();

    SubPrivateDerived sprd;
    sprd.accessBaseMembers();

    return 0;
}
