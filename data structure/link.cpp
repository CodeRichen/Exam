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
        cout << "list���{�b����!!!\n";
    else {
        cout << "list����:";
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
        cout << "A1125515 Linked list�ϥΤ���\n1. �C�X�������\n2. "
            "�s�W�@����ƨ�̫᭱\n3. "
            "�s�W�@����ƨ���w��m\n4. �R���̫᭱�����\n5. "
            "�R�����w��m�����\n6. ����list\n0. ���}\n\n��ܾާ@ : ";
        cin >> w;
        if (w == 0) break;
        switch (w) {
        case 1:
            printList(z);
            break;
        case 2:
            cout << "�п�J�n�s�W�����:";
            cin >> a;
            insertAtTail(z, a);
            break;
        case 3:
            cout << "�п�J�n���J����m:";
            cin >> a;
            cout << "�п�J�n�s�W�����:";
            cin >> w;
            insertAtAny(z, w, a);
            break;
        case 4:
            deletebake(z);
            break;
        case 5:
            cout << "�п�J�n�R������m:";
            cin >> a;
            deleteAny(z, a);
            break;
        case 6:
            upsidedown(z);
            break;
        }
    }
}
// �u��head���Ф~�ઽ�����ȡA�M��O�������ǤJ���ܼơA�᭱�����@�w�n�z�L.next�A�åB�����ϥμȮɪ����СA���M��ʨ�ǤJ�����з|���Y���ж]���A�ҥH�n���}�B�z�Cinsert��̫�O�]��̫᪺�e�@�Ӭ���Adelete�h�O�e��ӡC�Ƶ{���α�����m���覡�i�ٲ�private�Apublic�Cnext�i�令��L�ܼơC�C��ۭq�q���~�ϥθ�Ƶ��c�����D�A�N�������N���Q�n���ѪG�C�ӧR���̫�Ȫ��\��ݦҼ{�šA�u���@�ӡA�h�ӡA�T�ظѪG��if&else�A�O�ӳ����C