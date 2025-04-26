#include <iostream>
using namespace std;

// 定義 Stack 類別
class Stack {
    int *data;      // 用來儲存資料的陣列
    int top_idx;    // 指向堆疊頂端的索引
    int capacity;   // 堆疊最大容量
public:
    Stack(int cap) : top_idx(-1), capacity(cap) {
        data = new int[cap];
    }
    ~Stack() { delete[] data; }
    bool empty() const { return top_idx == -1; }
    bool full() const { return top_idx + 1 == capacity; }
    void push(int x) {
        if (!full()) data[++top_idx] = x;
    }
    void pop() {
        if (!empty()) --top_idx;
    }
    int top() const {
        if (!empty()) return data[top_idx];
        return -1; // 空堆疊時回傳 -1
    }
    int size() const { return top_idx + 1; }
    void print() const {
        for (int i = top_idx; i >= 0; --i) {
            cout << data[i] << (i == 0 ? "" : " ");
        }
        if (top_idx >= 0) cout << "\n";
    }
};

// 定義 Queue 類別（環狀佇列）
class Queue {
    int *data;
    int head, tail, cnt, capacity;
public:
    Queue(int cap) : head(0), tail(0), cnt(0), capacity(cap) {
        data = new int[cap];
    }
    ~Queue() { delete[] data; }
    bool empty() const { return cnt == 0; }
    bool full() const { return cnt == capacity; }
    void enqueue(int x) {
        if (!full()) {
            data[tail] = x;
            tail = (tail + 1) % capacity;
            ++cnt;
        }
    }
    int dequeue() {
        if (empty()) return -1;
        int x = data[head];
        head = (head + 1) % capacity;
        --cnt;
        return x;
    }
    int size() const { return cnt; }
    void print() const {
        for (int i = 0; i < cnt; ++i) {
            int idx = (head + i) % capacity;
            cout << data[idx] << (i + 1 == cnt ? "" : " ");
        }
        if (cnt > 0) cout << "\n";
    }
};

// 輔助函數：同時列印 Q, S1, S2 的狀態
void printAll(const Queue &Q, const Stack &S1, const Stack &S2) {
    if (!Q.empty())  Q.print();
    if (!S1.empty()) S1.print();
    if (!S2.empty()) S2.print();
}

int main() {
    int N;
    cin >> N;
    int *A = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];  // 讀取輸入陣列
    }

    Stack S1(N), S2(N);
    Queue Q(N);

    for (int i = 0; i < N; i++) {
        int x = A[i];

        // 先嘗試插入 S1
        if (S1.empty() || x < S1.top()) {
            S1.push(x);
            printAll(Q, S1, S2);
        }
        // 否則嘗試插入 S2
        else if (S2.empty() || x > S2.top()) {
            S2.push(x);
            printAll(Q, S1, S2);
        }
        // 如果兩邊都無法直接插入
        else {
            bool chooseS1 = (abs(x - S1.top()) < abs(x - S2.top()));
            Stack &C = chooseS1 ? S1 : S2;

            // 把 C 中的元素 pop 出來進到 Q，直到 x 可以插入
            while (!(C.empty() || (chooseS1 ? (x < C.top()) : (x > C.top())))) {
                Q.enqueue(C.top());
                C.pop();
            }

            C.push(x);
            printAll(Q, S1, S2);

            // 把 Q 的元素放回 C（根據題目的特殊移動邏輯）
            while (!Q.empty()) {
                int r = Q.size() - 1;
                while (r--) {
                    int v = Q.dequeue();
                    Q.enqueue(v);  // 先繞一圈，維持順序
                }
                int v = Q.dequeue(); // 真正要放回 stack 的
                C.push(v);
            }
        }
    }

    // 將 S2 的內容倒進 Q
    while (!S2.empty()) {
        Q.enqueue(S2.top());
        S2.pop();
    }
    while (!Q.empty()) {
        S2.push(Q.dequeue());
    }

    // 將 S1 與 S2 的元素兩兩比較後放進 Q
    while (!S1.empty() && !S2.empty()) {
        if (S1.top() < S2.top()) {
            Q.enqueue(S1.top());
            S1.pop();
        } else {
            Q.enqueue(S2.top());
            S2.pop();
        }
        printAll(Q, S1, S2);
    }

    // 將剩餘元素依序放入 Q
    while (!S1.empty()) {
        Q.enqueue(S1.top());
        S1.pop();
        printAll(Q, S1, S2);
    }
    while (!S2.empty()) {
        Q.enqueue(S2.top());
        S2.pop();
        printAll(Q, S1, S2);
    }

    delete[] A;
    return 0;
}
