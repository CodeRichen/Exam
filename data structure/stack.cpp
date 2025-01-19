#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int* arr;
    int capacity;

public:
    Stack(int maxSize) : top(-1), capacity(maxSize) {
        arr = new int[maxSize];
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack s(5); // 設定堆疊最大大小
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;

    return 0;
}
