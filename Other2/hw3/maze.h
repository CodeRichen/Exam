#ifndef MAZE_H
#define MAZE_H

const int k = 100;

struct Point {
    int r, c, d;
};

template <class T>
class Stack {
public:
    T* arr;
    int cap, topIndex;
    Stack(int size = 1000);
    ~Stack();
    void pop();
    void push(const T& a);
    bool empty();
    T top();
};

class M {
private:
    char m1[k][k], m3[k][k];
    bool m2[k][k];
    int row = 0, col = 0;
    int sr, sc, er, ec;
    int dr[8] = { 0, -1,  1,  0, -1, -1, 1, 1 };
    int dc[8] = { 1,  0,  0, -1, -1,  1, 1, -1 };
    char symbol[8] = { '-', '|', '|', '-', '\\', '/', '\\', '/' };

public:
    void readInput();
    void solve();
};

#endif
