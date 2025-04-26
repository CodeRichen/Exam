#include<iostream>
using namespace std;
struct Point {
    int r, c, d;
};

template <class T>
class Stack {
public:
    T* arr;
    int capacity, top;
    Stack(int size) : capacity(size), top(-1) {
        arr = new T[capacity];
    }
    ~Stack();
    void pop(){
        top-=1;
    };
    void push(const T& a){
        arr[top++]=a;
    };
    bool empty(){
        return top==-1
    };
    T top(){
        return arr[top];
    };
};

template <class T>
class queue {
public:
    T* arr;
    int capacity, top, down;
    queue(int size) : capacity(size), top(-1),down(-1) {
        arr = new T[capacity];
    }
    ~queue();
    void pop(){
        down+=1;
    };
    void push(const T& a){
        arr[top++]=a;

    };
    T top(){
        return arr[top];
    };
};
int main(){
    Stack<Point> stk;
    stk.push();

}
