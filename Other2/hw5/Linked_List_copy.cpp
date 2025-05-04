#include "Linked_List_copy.h"
#include <iostream>
using namespace std;

// ---------------- Tracklist -------------------

template <class M>
Tracklist<M>::~Tracklist() {
    Tracknode<M>* current = head;
    while (current) {
        Tracknode<M>* temp = current;
        current = current->next;
        delete temp;
    }
}

template <class M>
void Tracklist<M>::ReverseTrack() {
    Tracknode<M>* prev = nullptr;
    Tracknode<M>* current = head;
    while (current) {
        Tracknode<M>* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// ---------------- Albumlist -------------------

template <class M>
void Albumlist<M>::PushFrontAlbum(const M& A) {
    Albumnode<M>* newAlbum = new Albumnode<M>(A);
    newAlbum->next = head;
    head = newAlbum;
}

template <class M>
void Albumlist<M>::PushBackAlbum(const M& A) {
    Albumnode<M>* newAlbum = new Albumnode<M>(A);
    if (!head) {
        head = newAlbum;
        return;
    }
    Albumnode<M>* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newAlbum;
}

template <class M>
void Albumlist<M>::InsertAtAlbum(const M& A, int P) {
    if (P <= 0 || !head) {
        PushFrontAlbum(A);
        return;
    }
    Albumnode<M>* temp = head;
    for (int i = 0; temp->next && i < P - 1; ++i)
        temp = temp->next;
    Albumnode<M>* newAlbum = new Albumnode<M>(A);
    newAlbum->next = temp->next;
    temp->next = newAlbum;
}

template <class M>
void Albumlist<M>::PushFrontTrack(const M& T, int C, const M& A) {
    Albumnode<M>* album = head;
    while (album && album->name != A) album = album->next;
    if (!album) return;
    Tracknode<M>* newTrack = new Tracknode<M>(const_cast<M&>(T), C);
    newTrack->next = album->tracks->head;
    album->tracks->head = newTrack;
}

template <class M>
void Albumlist<M>::PushBackTrack(const M& T, int C, const M& A) {
    Albumnode<M>* album = head;
    while (album && album->name != A) album = album->next;
    if (!album) return;
    Tracknode<M>* newTrack = new Tracknode<M>(const_cast<M&>(T), C);
    if (!album->tracks->head) {
        album->tracks->head = newTrack;
        return;
    }
    Tracknode<M>* temp = album->tracks->head;
    while (temp->next) temp = temp->next;
    temp->next = newTrack;
}

template <class M>
void Albumlist<M>::InsertAtTrack(const M& T, int C, const M& A, int P) {
    Albumnode<M>* album = head;
    while (album && album->name != A) album = album->next;
    if (!album) return;
    if (P <= 0 || !album->tracks->head) {
        PushFrontTrack(T, C, A);
        return;
    }
    Tracknode<M>* temp = album->tracks->head;
    for (int i = 0; temp->next && i < P - 1; ++i)
        temp = temp->next;
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
        delete album->tracks->head;
        album->tracks->head = nullptr;
        return;
    }
    Tracknode<M>* temp = album->tracks->head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
}

template <class M>
void Albumlist<M>::RemoveTrackAt(const M& A, int P) {
    if (P <= 0) {
        PopTrack(A);
        return;
    }
    Albumnode<M>* album = head;
    while (album && album->name != A) album = album->next;
    if (!album || !album->tracks->head || !album->tracks->head->next) return;
    Tracknode<M>* temp = album->tracks->head;
    for (int i = 0; temp->next && i < P - 1; ++i)
        temp = temp->next;
    if (!temp->next) return;
    Tracknode<M>* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

template <class M>
void Albumlist<M>::PrintTrack(const M& A) const {
    Albumnode<M>* album = head;
    while (album && album->name != A) album = album->next;
    if (!album) {
        cout << "Album not found.\n";
        return;
    }
    Tracknode<M>* temp = album->tracks->head;
    while (temp) {
        cout << temp->name << " (" << temp->playCount << ")\n";
        temp = temp->next;
    }
}
