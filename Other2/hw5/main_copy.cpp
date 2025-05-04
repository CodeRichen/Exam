
#include <iostream>
#include <string>
#include "Linked_List.h"
using namespace std;

int main() {
    Albumlist<string> playlist;
    string command;

    while (cin >> command) {
        if (command == "PushFrontAlbum") {
            string albumName;
            cin >> albumName;
            playlist.PushFrontAlbum(albumName);
        } else if (command == "PushBackAlbum") {
            string albumName;
            cin >> albumName;
            playlist.PushBackAlbum(albumName);
        } else if (command == "InsertAlbum") {
            string albumName;
            int pos;
            cin >> albumName >> pos;
            playlist.InsertAtAlbum(albumName, pos);
        } else if (command == "PushFrontTrack") {
            string trackName, albumName;
            int count;
            cin >> trackName >> count >> albumName;
            playlist.PushFrontTrack(trackName, count, albumName);
        } else if (command == "PushBackTrack") {
            string trackName, albumName;
            int count;
            cin >> trackName >> count >> albumName;
            playlist.PushBackTrack(trackName, count, albumName);
        } else if (command == "InsertTrack") {
            string trackName, albumName;
            int count, pos;
            cin >> trackName >> count >> albumName >> pos;
            playlist.InsertAtTrack(trackName, count, albumName, pos);
        } else if (command == "PopTrack") {
            string albumName;
            cin >> albumName;
            playlist.PopTrack(albumName);
        } else if (command == "RemoveLastTrack") {
            string albumName;
            cin >> albumName;
            playlist.RemoveLastTrack(albumName);
        } else if (command == "RemoveTrackAt") {
            string albumName;
            int pos;
            cin >> albumName >> pos;
            playlist.RemoveTrackAt(albumName, pos);
        } else if (command == "Play") {
            playlist.Play();
        } else if (command == "Next") {
            playlist.Next();
        } else if (command == "PopAlbum") {
            playlist.PopAlbum();
        } else if (command == "RemoveLastAlbum") {
            playlist.RemoveLastAlbum();
        } else if (command == "RemoveAlbumAt") {
            int pos;
            cin >> pos;
            playlist.RemoveAlbumAt(pos);
        } else if (command == "ReverseAlbums") {
            playlist.ReverseAlbum();
        } else if (command == "ReverseTracks") {
            string albumName;
            cin >> albumName;
            Albumnode<string>* album = playlist.FindAlbum(albumName);
            if (album) album->tracks->ReverseTrack();
        } else if (command == "PrintAlbums") {
            playlist.PrintAlbum();
        } else if (command == "PrintTracks") {
            string albumName;
            cin >> albumName;
            playlist.PrintTrack(albumName);
        } else if (command == "END") {
            break;
        }
    }

    return 0;
}
