#include <iostream>
using namespace std;

template <typename T>
class Storage {
public:
    int add(T a, T b) { // �ҪO���
        return a + b;
    }

    T mul(T a, int b) { // �D�ҪO���
        return a*b ; // �T�w�� int �����k
    }
};

int main() {
    Storage<float> storage; // �ҪO���O����Ҥ�
    cout << "Addition: " << storage.add(1.5f, 2.5f) << "\n"; // ���T�եμҪO���
    cout << "Multiplication: " << storage.mul(1.5f, 2.5f) << "\n"; // �եΫD�ҪO���
    return 0;
}
