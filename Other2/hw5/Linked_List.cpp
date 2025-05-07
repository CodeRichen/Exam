//Linked_List.cpp
#include "Linked_List.h"
#include <iostream>
#include <string>  


template class Tracklist<std::string>;
template class Albumlist<std::string>;

using namespace std;

template <class M>
Tracklist<M>::~Tracklist(){
    Tracknode<M>* currend = head;
    while (currend != nullptr) {
       Tracknode<M>* temp = currend;
        currend = currend->next;
        delete temp; 
    }
}


template <class M>
Albumlist<M>::Albumlist() : head(nullptr) {}

template <class M>
Albumlist<M>::~Albumlist() {
    Albumnode<M>* current = head;
    while (current != nullptr) {
        Albumnode<M>* temp = current;
        current = current->next;
        delete temp;
    }
}

template <class M>
void Albumlist<M>::PushFrontAlbum(const M& A) {
    Albumnode<M>* newAlbum = new Albumnode<M>(A);
    newAlbum->next = head;
    head = newAlbum;
}

template <class M>
void Albumlist<M>::PushBackAlbum(const M& A) {
    if (!head) {
        PushFrontAlbum(A);
        return;
    }
    Albumnode<M>* newAlbum = new Albumnode<M>(A);
    Albumnode<M>* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newAlbum;
}

template <class M>
void Albumlist<M>::InsertAtAlbum(const M& A, int P) {
    if (P == 1 || !head) {
        PushFrontAlbum(A);
        return;
    }
    Albumnode<M>* temp = head;
    int i = 0;
    while (temp->next && i < P - 2) {
        temp = temp->next;
        i++;
    }
    if (!temp->next && i<P-2) return; 
    Albumnode<M>* newAlbum = new Albumnode<M>(A);
    newAlbum->next = temp->next;
    temp->next = newAlbum;
}

template <class M>
void Albumlist<M>::PopAlbum() {
    if (!head) return;
    Albumnode<M>* temp = head;
    head = head->next;
    delete temp;
}

template <class M>
void Albumlist<M>::RemoveLastAlbum() {
    if (!head) return;
    if (!head->next) {
        PopAlbum();
        return;
    }
    Albumnode<M>* temp = head;
    while (temp->next && temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

template <class M>
void Albumlist<M>::RemoveAlbumAt(int P) {
    if (P == 1 || !head) {
        PopAlbum();
        return;
    }
    Albumnode<M>* temp = head;
    int i = 0;
    while (temp->next && i < P - 2) {
        temp = temp->next;
        i++;
    }
    // 好像可以不用阻止它刪除nullptr...
    Albumnode<M>* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}


template <class M>
void Albumlist<M>::PushFrontTrack(const M& T, int C, const M& A) {
    Albumnode<M>* album = head;
    while (album && album->name != A) album = album->next;
    // if (!album) return;
    Tracknode<M>* newTrack = new Tracknode<M>(T, C);
    newTrack->next = album->tracks->head;
    album->tracks->head = newTrack;
}

template <class M>
void Albumlist<M>::PushBackTrack(const M& T, int C, const M& A) {
    Albumnode<M>* album = head;
    while (album && album->name != A) album = album->next;
    if (!album) return;
    if (!album->tracks->head) {
        PushFrontTrack(T, C, A);
        return;
    }
    Tracknode<M>* newTrack = new Tracknode<M>(T, C);
    Tracknode<M>* temp = album->tracks->head;
    while (temp->next) temp = temp->next;
    temp->next = newTrack;
}

template <class M>
void Albumlist<M>::InsertTrack(const M& T, int C, const M& A, int P) {
    Albumnode<M>* album = head;
    while (album && album->name != A) album = album->next;
    if (!album) return;
    if (P == 1 || !album->tracks->head) {
        PushFrontTrack(T, C, A);
        return;
    }
    Tracknode<M>* temp = album->tracks->head;
    int i = 0;
    while (temp->next && i < P-2 ) {
        temp = temp->next;
        i++;
    }
    if (!temp->next & i<P-2) return; 
    Tracknode<M>* newTrack = new Tracknode<M>(const_cast<M&>(T), C);
    newTrack->next = temp->next;
    temp->next = newTrack;
}

template <class M>
void Albumlist<M>::PopTrack(const M& A) {
    Albumnode<M>* album = head;
    while (album && album->name != A) album = album->next;
    if (!album || !album->tracks->head) return;
    Tracknode<M>* temp = album->tracks->head;
    album->tracks->head = temp->next;
    delete temp;
}

template <class M>
void Albumlist<M>::RemoveLastTrack(const M& A) {
    Albumnode<M>* album = head;
    while (album && album->name != A) album = album->next;
    if (!album || !album->tracks->head) return;
    if (!album->tracks->head->next) {
        PopTrack(A);
        return;
    }
   
    Tracknode<M>* temp = album->tracks->head;
    while (temp->next->next) temp = temp->next;
    
    string removedName = temp->next->name;
    delete temp->next;
    temp->next = nullptr;

    
}

template <class M>
void Albumlist<M>::RemoveAtTrack(const M& A, int P) {
    Albumnode<M>* album = head;
    while (album && album->name != A) album = album->next;
    if (!album || !album->tracks->head) return;
    if (P == 0 || !album->tracks->head) {
        PopTrack(A);
        return;
    }
    Tracknode<M>* temp = album->tracks->head;
    int i = 0;
    while (temp->next && i < P-2) {
        temp = temp->next; 
        i++;
    }
    if (!temp->next && i<P-2) return;
    Tracknode<M>* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

template <class M>  
void Albumlist<M>::PrintTrack(const M& A) const {
    Albumnode<M>* album = head;
    while (album && album->name != A) album = album->next;
    if (!album || !album->tracks->head) return;
    Tracknode<M>* temp = album->tracks->head;
    while (temp) {
        cout << temp->name << " " ;
        temp = temp->next;
    }
    cout <<"\n";
}

template <class M>
void Albumlist<M>::PrintAlbum() const {
    Albumnode<M>* temp = head;
    while (temp) {
        cout << temp->name  << " ";
        temp = temp->next;
    }
    cout <<"\n";
}

template <class M>
void Albumlist<M>::Play() {
    Albumnode<M>* album = head;
    if (!album) return;
    Tracknode<M>* track = album->tracks->head;
    if (!track) return;
    cout << track->name << "\n";
    // track->playCount++;
}

template <class M>
void Albumlist<M>::Next() {
    bool first=true;
    while (head) {
        Tracknode<M>*& trackHead = head->tracks->head;
        if (trackHead) {
            if (!first) {
               return;
            }
            first=false;
            Tracknode<M>* temp = trackHead;
            trackHead = trackHead->next;
            delete temp;
            if (trackHead) return;
        }

        Albumnode<M>* tempAlbum = head;
        head = head->next;
        delete tempAlbum;
    }
}


template <class M>
void Albumlist<M>::ReverseTracks(const M& A) {
    Albumnode<M>* album = head;
    while (album && album->name != A) album = album->next;

    Tracknode<M>* prev = nullptr;
    Tracknode<M>* curr = album->tracks->head;
    Tracknode<M>* next = nullptr;
    while (curr) {
        Tracknode<M>* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    album->tracks->head = prev;
    
}

template <class M>
void Albumlist<M>::ReverseAlbum() {
    Albumnode<M>* prev = nullptr;
    Albumnode<M>* cur = head;
    Albumnode<M>* next = nullptr;
    
    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

template <class M>
Tracknode<M>* Albumlist<M>::MergeAllTracks() {
    Tracknode<M>* mergedHead = nullptr;
    Tracknode<M>* mergedTail = nullptr;

    Albumnode<M>* album = head;
    while (album) {
        Tracknode<M>* track = album->tracks->head;
        while (track) {
            Tracknode<M>* newNode = new Tracknode<M>(track->name, track->playCount);
            if (!mergedHead) {
                mergedTail = newNode;
                mergedHead = mergedTail;
            } else {
                mergedTail->next = newNode;
                mergedTail = newNode;
            }
            track = track->next;
        }
        album = album->next;
    }
    return mergedHead;
}

template <class M>
Tracknode<M>* Albumlist<M>::MergeSort(Tracknode<M>* head) {
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
Tracknode<M>* Albumlist<M>::Merge(Tracknode<M>* a, Tracknode<M>* b) {
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
template <class M>
void Albumlist<M>::PrintSortedTracks() {
    Tracknode<M>* merged = MergeAllTracks();
    Tracknode<M>* sorted = MergeSort(merged);
    
    cout <<"\n";
    while (sorted) {
        cout << sorted->name << " " << sorted->playCount  <<"\n";
        Tracknode<M>* temp = sorted;
        sorted = sorted->next;
        delete temp;  
    }
}
