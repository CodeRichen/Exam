//Linked_List.h
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <string>
using namespace std;

template <class M>
struct Tracknode {
    M name;
    int playCount;
    Tracknode* next;
    Tracknode(const M& n, int c) : name(n), playCount(c), next(nullptr) {}
    ~Tracknode() = default;

};

template <class M>
class Tracklist {
public: 
    Tracknode<M>* head;
    Tracklist() : head(nullptr) {}
    ~Tracklist();
};

template <class M>
struct Albumnode {
    M name;
    Tracklist<M>* tracks;
    Albumnode* next;
    Albumnode(const M& n) : name(n), next(nullptr) {
        tracks = new Tracklist<M>(); //連結到下一層
    }

    ~Albumnode() {
        delete tracks;
    }
};


template <class M>
class Albumlist {
public:
    Albumnode<M>* head;
    Albumlist();
    ~Albumlist();
    void Play();
    void Next();
    void PushFrontAlbum(const M& A);
    void PushBackAlbum(const M& A);
    void InsertAtAlbum(const M& A, int P);
    void PopAlbum();
    void RemoveLastAlbum();
    void RemoveAlbumAt(int P);
    void ReverseAlbum();
    void ReverseTracks(const M& A);
    void PrintAlbum() const;
    void PushFrontTrack(const M& T, int C, const M& A);
    void PushBackTrack(const M& T, int C, const M& A);
    void InsertTrack(const M& T, int C, const M& A, int P);
    void PopTrack(const M& A);
    void RemoveLastTrack(const M& A);
    void RemoveAtTrack(const M& A, int P);
    void PrintTrack(const M& A) const;
    Tracknode<M>* MergeAllTracks();
    Tracknode<M>* MergeSort(Tracknode<M>* head);   
    Tracknode<M>* Merge(Tracknode<M>* a, Tracknode<M>* b); 
    void PrintSortedTracks();  
};

#endif
