#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* arr;

public:
    Queue(int maxSize) : front(0), rear(-1), size(0) {
        arr = new int[maxSize];
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull(int maxSize) const {
        return size == maxSize;
    }

    void enqueue(int value, int maxSize) {
        if (isFull(maxSize)) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % maxSize;
        arr[rear] = value;
        size++;
    }

    int dequeue(int maxSize) {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % maxSize;
        size--;
        return value;
    }

    int peek() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q(5); // 設定佇列最大大小
    q.enqueue(10, 5);
    q.enqueue(20, 5);
    q.enqueue(30, 5);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue(5);
    cout << "Front element after dequeue: " << q.peek() << endl;

    return 0;
}
