#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

int main() {
    const int N = 5;
    char values[N] = {'a', 'b', 'c', 'd', 'e'};
    Node* nodes[N];

    for (int i = 0; i < N; i++)
        nodes[i] = new Node{values[i], nullptr};

    for (int i = 0; i < N - 1; i++)
        nodes[i]->next = nodes[i + 1];

    Node* current = nodes[0];
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    for (int i = 0; i < N; i++)
        delete nodes[i];

    return 0;
}
