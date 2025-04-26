#include <iostream>
#include <string>
#include "maze.h"

using namespace std;


template <class T>
Stack<T>::Stack(int size) {
    cap = size;
    arr = new T[cap];
    topIndex = -1;
}
template <class T>
Stack<T>::~Stack() {
    delete[] arr;
}
template <class T>
void Stack<T>::pop() {
    topIndex--;
}
template <class T>
void Stack<T>::push(const T& a) {
    topIndex++;
    arr[topIndex] = a;
}
template <class T>
bool Stack<T>::empty() {
    return topIndex == -1;
}
template <class T>
T Stack<T>::top() {
    return arr[topIndex];
}


void M::readInput() {
    string q;
    while (getline(cin, q)) {
        if (q.empty()) break;
        col = 0;
        for (char ch : q) {
            if (ch == ' ') continue;
            m1[row][col] = ch;
            m2[row][col] = false;
            m3[row][col] = ch;
            if (ch == 's') { sr = row; sc = col; }
            if (ch == 'e') { er = row; ec = col; }
            col++;
        }
        row++;
    }
}

void M::solve() {
    Stack<Point> stk;
    m2[sr][sc] = true;
    stk.push({ sr, sc, 0 });

    bool found = false;
    while (!stk.empty() && !found) {
        Point p1 = stk.top();
        stk.pop();
        int r = p1.r, c = p1.c, d = p1.d;

        while (d < 8 && !found) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr == er && nc == ec) {
                stk.push({ r, c, d + 1 });
                int tr = -1, tc = -1;
                while (!stk.empty()) {
                    Point b = stk.top(); stk.pop();
                    if (tr != -1) m3[tr][tc] = symbol[b.d - 1];
                    tr = b.r; tc = b.c;
                }
                found = true;
                break;
            }

            if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                m1[nr][nc] != 'b' && !m2[nr][nc]) {
                m2[nr][nc] = true;
                stk.push({ r, c, d + 1 });
                r = nr; c = nc; d = 0;
            } else {
                d++;
            }
        }
    }

    if (found) {
        int steps = 1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << m3[i][j];
                if (j < col - 1) cout << " ";
                if (m3[i][j] == '-' || m3[i][j] == '|' || m3[i][j] == '/' || m3[i][j] == '\\')
                    steps++;
            }
            cout << endl;
        }
        cout << "Total " << steps << " Steps." << endl;
    }
}


template class Stack<Point>;
