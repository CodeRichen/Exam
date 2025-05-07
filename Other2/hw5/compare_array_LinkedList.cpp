// 版本：不使用 STL 容器，改用手動建立 linked list 及 array
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

//================== Linked List 定義 ===================
template<typename T>
struct ListNode {
    T val;
    ListNode* next;
    ListNode(T v) : val(v), next(nullptr) {}
};

// 找中點
template<typename T>
ListNode<T>* getMiddle(ListNode<T>* head) {
    if (!head || !head->next) return head;
    ListNode<T>* slow = head;
    ListNode<T>* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 合併兩個已排序鏈結串列
template<typename T>
ListNode<T>* merge(ListNode<T>* a, ListNode<T>* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->val < b->val) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

// Merge Sort for Linked List
template<typename T>
ListNode<T>* mergeSortList(ListNode<T>* head) {
    if (!head || !head->next) return head;
    ListNode<T>* mid = getMiddle(head);
    ListNode<T>* right = mid->next;
    mid->next = nullptr;
    return merge(mergeSortList(head), mergeSortList(right));
}

//================== Array Merge Sort ===================
void mergeArray(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (int i = left; i <= right; ++i) arr[i] = temp[i];
}

void mergeSortArray(int arr[], int temp[], int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSortArray(arr, temp, left, mid);
    mergeSortArray(arr, temp, mid + 1, right);
    mergeArray(arr, temp, left, mid, right);
}

//================== Main Function ===================
int main() {
    const int N = 100000;
    srand(time(0));

    // 原始資料陣列
    int* data = new int[N];
    for (int i = 0; i < N; ++i) data[i] = rand();

    // 複製資料陣列
    int* arrayData = new int[N];
    int* tempArray = new int[N];
    for (int i = 0; i < N; ++i) arrayData[i] = data[i];

    // 建立 Linked List
    ListNode<int>* listHead = new ListNode<int>(data[0]);
    ListNode<int>* curr = listHead;
    for (int i = 1; i < N; ++i) {
        curr->next = new ListNode<int>(data[i]);
        curr = curr->next;
    }

    // Array Merge Sort
    auto start1 = high_resolution_clock::now();
    mergeSortArray(arrayData, tempArray, 0, N - 1);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1);
    cout << "Array Merge Sort time: " << duration1.count() << " ms" << endl;

    // Linked List Merge Sort
    auto start2 = high_resolution_clock::now();
    listHead = mergeSortList(listHead);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2);
    cout << "Linked List Merge Sort time: " << duration2.count() << " ms" << endl;

    // 釋放記憶體
    delete[] data;
    delete[] arrayData;
    delete[] tempArray;
    while (listHead) {
        ListNode<int>* temp = listHead;
        listHead = listHead->next;
        delete temp;
    }

    return 0;
}