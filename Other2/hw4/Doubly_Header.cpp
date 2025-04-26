#include <iostream>
using namespace std;

template <class T>
class DNode {
public:
    T data;
    DNode<T>* prev;
    DNode<T>* next;

    DNode(const T& data = T(), DNode<T>* prev = nullptr, DNode<T>* next = nullptr)
        : data(data), prev(prev), next(next) {}
};

template <class T>
class DLinkedList {
public:
    DLinkedList() {
        header = new DNode<T>();  
        header->next = header;
        header->prev = header;
    }

    ~DLinkedList() {
        DNode<T>* current = header->next;
        while (current != header) {
            DNode<T>* temp = current;
            current = current->next;
            delete temp;
        }
        delete header;
    }

    void append(const T& data) {
        //假設初始串列為：
        //Header <-> A <-> B <-> C <-> Header  (環狀)
        DNode<T>* newNode = new DNode<T>(data);//建立一個新節點 D，它目前還沒連上串列
        DNode<T>* last = header->prev; //header->prev 是目前的尾端，也就是 C
        newNode->next = header; //D 的下一個指向 header
        newNode->prev = last; //D 的前一個指向 C
        last->next = newNode; //C 的 next 改為指向 D
        header->prev = newNode; //header 的 prev 改為 D
    }

    void print() const {
        DNode<T>* current = header->next;
        cout << "(header)<-> "  ;
        while (current != header) {
            cout << current->data;
            if (current->next != header) cout << " <-> ";
            current = current->next;
        }
        cout << " <-> (header)" << endl;
    }

private:
    DNode<T>* header;  
};

int main() {
    DLinkedList<char> list;
    for (char ch = 'a'; ch <= 'e'; ++ch)
        list.append(ch);
    list.print();  
}
