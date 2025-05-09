#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template<class M>
struct Tracknode {
    string name;
    int playCount;
    Tracknode* next;
    Tracknode(string n, int p) : name(n), playCount(p), next(nullptr) {}
};

template<class M>
Tracknode<M>* trackHead = nullptr;

template<class M>
void PushBackTrack(Tracknode<M>*& head, string name, int playCount) {
    Tracknode<M>* newNode = new Tracknode<M>(name, playCount);
    if (!head) {
        head = newNode;
        return;
    }
    Tracknode<M>* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = newNode;
}

template<class M>
Tracknode<M>* Merge(Tracknode<M>* a, Tracknode<M>* b) {
    if (!a) return b;
    if (!b) return a;
    Tracknode<M>* result = nullptr;
    if (a->playCount >= b->playCount) {
        result = a;
        result->next = Merge(a->next, b);
    } else {
        result = b;
        result->next = Merge(a, b->next);
    }
    return result;
}

template<class M>
Tracknode<M>* MergeSort(Tracknode<M>* head) {
    if (!head || !head->next) return head;
    Tracknode<M>* slow = head;
    Tracknode<M>* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Tracknode<M>* mid = slow->next;
    slow->next = nullptr;

    Tracknode<M>* left = MergeSort(head);
    Tracknode<M>* right = MergeSort(mid);

    return Merge(left, right);
}

template <class M>
void PrintSortedTracks() {
    Tracknode<M>* sorted = MergeSort(trackHead<M>);
    cout << "\n";
    while (sorted) {
        cout << sorted->name << " " << sorted->playCount << "\n";
        Tracknode<M>* temp = sorted;
        sorted = sorted->next;
        delete temp;
    }
}

int main() {
    string cmd, name;
    int count;
    while (cin >> cmd >> name >> count) {
        if (cmd == "PushBackTrack") {
            PushBackTrack(trackHead<string>, name, count);
        }
    }

    PrintSortedTracks<string>();
    return 0;
}
