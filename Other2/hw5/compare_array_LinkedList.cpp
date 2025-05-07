#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

//================== Linked List 定義 ===================
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

// 分割中點
ListNode* getMiddle(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// 合併兩串
ListNode* merge(ListNode* a, ListNode* b) {
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
ListNode* mergeSortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* mid = getMiddle(head);
    ListNode* right = mid->next;
    mid->next = nullptr;
    return merge(mergeSortList(head), mergeSortList(right));
}

//================== Array Merge Sort ===================
void mergeArray(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (int i = left; i <= right; ++i) arr[i] = temp[i - left];
}

void mergeSortArray(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSortArray(arr, left, mid);
    mergeSortArray(arr, mid + 1, right);
    mergeArray(arr, left, mid, right);
}

//================== Main Function ===================
int main() {
    const int N = 100000;
    srand(time(0));
    
    vector<int> data(N);
    for (int& x : data) x = rand();

    // 複製資料
    vector<int> arrayData = data;
    ListNode* listHead = new ListNode(data[0]);
    ListNode* curr = listHead;
    for (int i = 1; i < N; ++i) {
        curr->next = new ListNode(data[i]);
        curr = curr->next;
    }

    // 計算 Array Merge Sort 時間
    auto start1 = high_resolution_clock::now();
    mergeSortArray(arrayData, 0, N - 1);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1);
    cout << "Array Merge Sort time: " << duration1.count() << " ms" << endl;

    // 計算 Linked List Merge Sort 時間
    auto start2 = high_resolution_clock::now();
    listHead = mergeSortList(listHead);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end2 - start2);
    cout << "Linked List Merge Sort time: " << duration2.count() << " ms" << endl;

    return 0;
}
