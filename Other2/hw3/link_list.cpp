#include <iostream>
using namespace std;

struct Node {
    char data;    
    Node* next;   
};


int main() {
   
    Node* a = new Node{'a', nullptr};
    Node* b = new Node{'b', nullptr};
    Node* c = new Node{'c', nullptr};
    Node* d = new Node{'d', nullptr};
    Node* e = new Node{'e', nullptr};

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Node* current = a;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;

}
