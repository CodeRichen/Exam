#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

// 歌曲節點
struct TrackNode {
    std::string name;
    int playCount;
    TrackNode* next;
    TrackNode(const std::string& n, int c);
};

// 歌曲列表
class TrackList {
public:
    TrackNode* head;
    TrackList();
    ~TrackList();
    void pushFront(const std::string& name, int count);
    void pushBack(const std::string& name, int count);
    void insertAt(int pos, const std::string& name, int count);
    void removeFront();
    void removeBack();
    void removeAt(int pos);
    void reverse();
    void print() const;
    void clear();
};

// 專輯節點
struct AlbumNode {
    std::string albumName;
    TrackList tracks;
    AlbumNode* next;
    AlbumNode(const std::string& name);
};

// 專輯播放列表
class AlbumList {
public:
    AlbumNode* head;
    AlbumList();
    ~AlbumList();
    void pushFront(const std::string& name);
    void pushBack(const std::string& name);
    void insertAt(int pos, const std::string& name);
    void removeFront();
    void removeBack();
    void removeAt(int pos);
    void reverse();
    void printAlbums() const;
    void printTracks(const std::string& albumName) const;
    void play() const;
    void next();
    void pushTrackFront(const std::string& albumName, const std::string& trackName, int count);
    void pushTrackBack(const std::string& albumName, const std::string& trackName, int count);
    void insertTrackAt(const std::string& albumName, int pos, const std::string& trackName, int count);
    void removeTrackFront(const std::string& albumName);
    void removeTrackBack(const std::string& albumName);
    void removeTrackAt(const std::string& albumName, int pos);
    void reverseTracks(const std::string& albumName);
    void clear();
};

#endif
