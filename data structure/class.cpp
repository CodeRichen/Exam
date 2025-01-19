#include <iostream>
#include <string>
#include "Class.h"
using namespace std;
namespace Garden {
    class Plant {
    private:
        struct KeyValuePair {
            string key;
            string color;
            string shape;
            float value;
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
        Plant(int capacity) : size(0), capacity(capacity) {
            arr = new KeyValuePair[capacity];
        }

        void insert(const string& key, float value, string color, string shape) {
            if (size < capacity) {
                arr[size].key = key;
                arr[size].value = value;
                arr[size].color = color;
                arr[size].shape = shape;
                size++;
            }
            else {
                cout << "The garden is full\n";
            }
        }
        void changecolor(const string& key, string color) {
            int index = findKey(key);
            arr[index].color = color;
        }
        void grow(const string& key, float value) {
            int index = findKey(key);
            arr[index].value += value;
        }
        void changeshape(const string& key, string shape) {
            int index = findKey(key);
            arr[index].shape = shape;
        }
        void get(const string& key) const {
            int index = findKey(key);
            cout << arr[index].key << " " << arr[index].value << " " << arr[index].color << " " << arr[index].shape << "\n";
        }
    };
    class Gardener {
    

    };
}

