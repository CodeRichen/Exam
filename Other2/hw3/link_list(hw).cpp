#include <iostream>
using namespace std;

template <class T>
class ChainNode {
public:
    T data;
    ChainNode<T>* link;
    ChainNode(const T& data = T(), ChainNode<T>* link = nullptr)  : data(data), link(link) {}
    };

template <class T>
class Chain {
public:
    Chain() : first(nullptr) {}
    ~Chain() {
        while (first) {
            ChainNode<T>* temp = first;
            first = first->link;
            delete temp; //直接刪除 current 會導致無法繼續遍歷。
        }
    }
    void append(const T& data) {
        ChainNode<T>* newNode = new ChainNode<T>(data);
        if (!first) {
            first = newNode;
            return;
        }
        ChainNode<T>* current = first;
        while (current->link) current = current->link;
        current->link = newNode;
    }
    void print() const {
        ChainNode<T>* current = first;
        while (current) {
            cout << current->data;
            if (current->link) cout << " -> ";
            current = current->link;
        }
        cout << " -> NULL" << endl;
    }

private:
    ChainNode<T>* first; //防止修改
};

int main() {
    Chain<char> list;
    for (char ch = 'a'; ch <= 'e'; ++ch)
        list.append(ch);
    list.print();
}


