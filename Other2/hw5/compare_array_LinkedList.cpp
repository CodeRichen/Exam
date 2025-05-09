#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;
const int N = 65000;

template<typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(T v) : val(v), next(nullptr) {}
};



template<typename T>
ListNode<T>* mergeSort(ListNode<T>* head) {
    if (!head || !head->next) return head;
    ListNode<T>* slow = head;
    ListNode<T>* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode<T>* mid = slow->next;
    slow->next = nullptr;

    ListNode<T>* left = mergeSort(head);
    ListNode<T>* right = mergeSort(mid);

    return mergeL(left, right);
}

template<typename T>
ListNode<T>* mergeL(ListNode<T>* a, ListNode<T>* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->val > b->val) {
        a->next = mergeL(a->next, b);
        return a;
    } else {
        b->next = mergeL(a, b->next);
        return b;
    }
}

int arr[N];

void merge(int left, int right) {
    int mid = (left + right) / 2;
    
    int temp[N];  
    int indexLeft = left;
    int indexRight = mid;
    int indexTemp = left;

    while (indexLeft < mid && indexRight < right) {
        if (arr[indexLeft] > arr[indexRight]) {
            temp[indexTemp++] = arr[indexLeft++];
        } else {
            temp[indexTemp++] = arr[indexRight++];
        }
    }

    while (indexLeft < mid) {
        temp[indexTemp++] = arr[indexLeft++];
    }

    while (indexRight < right) {
        temp[indexTemp++] = arr[indexRight++];
    }

    for (int i = left; i < right; ++i) {
        arr[i] = temp[i];
    }
}

void mergeSort(int left, int right) {
    if (right - left <= 1) return;
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, right);
}

int main() {
    
    srand(time(0));
    for (int i = 0; i < N; ++i) arr[i] = rand();

    ListNode<int>* listHead = new ListNode<int>(rand());
    ListNode<int>* curr = listHead;
    for (int i = 1; i < N; ++i) {
        curr->next = new ListNode<int>(rand());
        curr = curr->next;
    }

    auto start1 = high_resolution_clock::now();
    mergeSort(0, N);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1);
    cout << "Array Merge Sort time: " << duration1.count() << " ms" << endl;

    // Linked List Merge Sort
    auto start2 = high_resolution_clock::now();
    listHead = mergeSort(listHead);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2);
    cout << "Linked List Merge Sort time: " << duration2.count() << " ms" << endl;

    while (listHead) {
        ListNode<int>* temp = listHead;
        listHead = listHead->next;
        delete temp;
    }

}