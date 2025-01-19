#include <iostream>
using namespace std;

class Set {
private:
    int* arr;
    int size;
    int capacity;

    bool contains(int value) const {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value)
                return true;
        }
        return false;
    }

public:
    Set(int capacity) : size(0), capacity(capacity) {
        arr = new int[capacity];
    }

    ~Set() {
        delete[] arr;
    }

    void insert(int value) {
        if (contains(value)) {
            cout << "Value " << value << " already exists in the set\n";
            return;
        }
        if (size < capacity) {
            arr[size++] = value;
        }
        else {
            cout << "Set is full\n";
        }
    }

    void remove(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                arr[i] = arr[size - 1];  // 將最後一個元素移到刪除位置
                size--;
                return;
            }
        }
        cout << "Value not found in the set\n";
    }

    bool contains(int value) const {
        return contains(value);
    }
};

int main() {
    Set set(10);  // 設定集合最大大小
    set.insert(5);
    set.insert(10);
    set.insert(5);  // 重複元素測試

    cout << "Set contains 10: " << (set.contains(10) ? "Yes" : "No") << endl;

    set.remove(10);
    cout << "Set contains 10 after removal: " << (set.contains(10) ? "Yes" : "No") << endl;

    return 0;
}
