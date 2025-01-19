#include <iostream>
using namespace std;

template <typename T>
class Storage {
public:
    int add(T a, T b) { // 家狾ㄧ计
        return a + b;
    }

    T mul(T a, int b) { // 獶家狾ㄧ计
        return a*b ; // ㏕﹚ int 猭
    }
};

int main() {
    Storage<float> storage; // 家狾摸龟ㄒて
    cout << "Addition: " << storage.add(1.5f, 2.5f) << "\n"; // タ絋秸ノ家狾ㄧ计
    cout << "Multiplication: " << storage.mul(1.5f, 2.5f) << "\n"; // 秸ノ獶家狾ㄧ计
    return 0;
}
