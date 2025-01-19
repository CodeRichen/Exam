#include <iostream>
#include <string>
using namespace std;

class Map {
private:
    struct KeyValuePair {
        string key;
        int value;
    };

    KeyValuePair* arr;
    int size;
    int capacity;

    int findKey(const string& key) const {
        for (int i = 0; i < size; i++) {
            if (arr[i].key == key)
                return i;
        }
        return -1;
    }

public:
    Map(int capacity) : size(0), capacity(capacity) {
        arr = new KeyValuePair[capacity];
    }

    ~Map() {
        delete[] arr;
    }

    void insert(const string& key, int value) {
        int index = findKey(key);
        if (index != -1) {
            arr[index].value = value;  // 更新已有的鍵的值
        }
        else if (size < capacity) {
            arr[size].key = key;
            arr[size].value = value;
            size++;
        }
        else {
            cout << "Map is full\n";
        }
    }

    int get(const string& key) const {
        int index = findKey(key);
        if (index != -1) {
            return arr[index].value;
        }
        cout << "Key not found\n";
        return -1;
    }

    void remove(const string& key) {
        int index = findKey(key);
        if (index != -1) {
            arr[index] = arr[size - 1];  // 將最後一個元素移到刪除位置
            size--;
        }
        else {
            cout << "Key not found\n";
        }
    }
};

int main() {
    Map map(10);  // 設定映射最大大小
    map.insert("Alice", 30);
    map.insert("Bob", 25);

    cout << "Alice's age: " << map.get("Alice") << endl;

    map.remove("Alice");
    cout << "Alice's age after removal: " << map.get("Alice") << endl;

    return 0;
}
