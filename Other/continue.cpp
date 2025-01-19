#include <iostream>
#include <vector>
using namespace std;

class Array {
private:
    vector<int> data;
public:
    Array(int size) : data(size, 0) { // ��l�ƫ��w�j�p���V�q
        cout << "Array of size " << size << " created." << endl;
    }
};

class B {
private:
    Array f;
    Array b;
public:
    B(int size) : f(size), b(size+10) { // ��l�ƦC��
        cout << "Class B constructed with size " << size << "." << endl;
    }
};

int main() {
    B obj(10); // �Ы� B ����H�A�ǤJ size = 10
    return 0;
}
