#include <bits/stdc++.h>
using namespace std;
struct q {
    int e;
    q* next;
    q(int w) : e(w), next(nullptr) {}
};

void insertAtAny(q*& t, int e, int a) {
    q* r = t;
    q* d = new q(e);
    if (--a == 0) {
        d->next = t;
        t = d;
        return;
    }

    a -= 1;
    while (a--) {
        r = r->next;
    }
    d->next = r->next;
    r->next = d;
}
void deleteAny(q*& t, int a) {
    q* r = t;
    if (a == 1) {
        t = r->next;
        delete r;
        return;
    }
    a -= 2;
    while (a--) {
        r = r->next;
    }
    r->next = r->next->next;
}
void insertAtTail(q*& r, int e) {
    q* d = new q(e);
    if (!r) {
        r = d;
        return;
    }
    q* t = r;
    while (t->next) {
        t = t->next;
    }
    t->next = d;
}
void deletebake(q*& t) {
    q* r = t;
    if (!r) return;
    if (!r->next) {
        delete t;
        t = nullptr;
    }
    else {
        while (r->next->next) {
            r = r->next;
        }
        delete r->next;
        r->next = nullptr;
    }
}

void printList(q*& t) {
    q* r = t;
    if (!r)
        cout << "list內現在為空!!!\n";
    else {
        cout << "list內有:";
        while (r) {
            cout << r->e << "->";
            r = r->next;
        }
        cout << "NULL"
            << "\n";
    }
}
void upsidedown(q*& f) {
    q* r = f;
    q* n = nullptr;
    q* p = nullptr;
    while (r != nullptr) {
        n = r->next;
        r->next = p;
        p = r;
        r = n;
    }
    f = p;
}

int main() {
    int w, a;
    q* z = nullptr;

    while (1) {
        cout << "A1125515 Linked list使用介面\n1. 列出全部資料\n2. "
            "新增一筆資料到最後面\n3. "
            "新增一筆資料到指定位置\n4. 刪除最後面的資料\n5. "
            "刪除指定位置的資料\n6. 反轉list\n0. 離開\n\n選擇操作 : ";
        cin >> w;
        if (w == 0) break;
        switch (w) {
        case 1:
            printList(z);
            break;
        case 2:
            cout << "請輸入要新增的資料:";
            cin >> a;
            insertAtTail(z, a);
            break;
        case 3:
            cout << "請輸入要插入的位置:";
            cin >> a;
            cout << "請輸入要新增的資料:";
            cin >> w;
            insertAtAny(z, w, a);
            break;
        case 4:
            deletebake(z);
            break;
        case 5:
            cout << "請輸入要刪除的位置:";
            cin >> a;
            deleteAny(z, a);
            break;
        case 6:
            upsidedown(z);
            break;
        }
    }
}
// 只有head指標才能直接給值，然後是直接給傳入的變數，後面的不一定要透過.next，並且必須使用暫時的指標，不然更動到傳入的指標會使頭指標跑掉，所以要分開處理。insert到最後是跑到最後的前一個為止，delete則是前兩個。副程式用接收位置的方式可省略private，public。next可改成其他變數。。能自訂義錯誤使用資料結構的問題，將報錯取代為想要的解果。而刪除最後值的功能需考慮空，只有一個，多個，三種解果的if&else，是個陷阱。