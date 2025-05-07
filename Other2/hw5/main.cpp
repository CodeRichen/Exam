//main.cpp
#include <iostream>
#include <string>
#include "Linked_List.h"

using namespace std;

int main() {
    Albumlist<string> playlist;
    string command;

    while (cin >> command) {
        if (command == "END") {
            playlist.PrintSortedTracks();
            break;
            }
        if (command == "PushFrontAlbum") {
            string A;
            cin >> A;
            playlist.PushFrontAlbum(A);

        } else if (command == "PushBackAlbum") {
            string A;
            cin >> A;
            playlist.PushBackAlbum(A);

        } else if (command == "InsertAlbum") {
            string A;
            int P;
            cin >> A >> P;
            playlist.InsertAtAlbum(A, P);

        } else if (command == "PrintAlbums") {
            playlist.PrintAlbum();

        } else if (command == "PushFrontTrack") {
            string T, A;
            int C;
            cin >> T >> C >> A;
            playlist.PushFrontTrack(T, C, A);

        } else if (command == "PushBackTrack") {
            string T, A;
            int C;
            cin >> T >> C >> A;
            playlist.PushBackTrack(T, C, A);

        } else if (command == "InsertTrack") {
            string T, A;
            int C, P;
            cin >> T >> C >> A >> P;
            playlist.InsertTrack(T, C, A, P);

        } else if (command == "PrintTracks") {
            string A;
            cin >> A;
            playlist.PrintTrack(A);

        } else if (command == "RemoveAtTrack") {
            string A;
            int P;
            cin >> A >> P;
            playlist.RemoveAtTrack(A, P);

        } else if (command == "RemoveLastTrack") {
            string A;
            cin >> A;
            playlist.RemoveLastTrack(A);

        } else if (command == "PopTrack") {
            string A;
            cin >> A;
            playlist.PopTrack(A);

        } else if (command == "Play") {
            playlist.Play();

        } else if (command == "Next") {
            playlist.Next();

        } else if (command == "ReverseAlbums") {
            playlist.ReverseAlbum();

        } 
        else if (command == "ReverseTracks") {
            
            string A;
            cin >> A;
            playlist.ReverseTracks(A);

        }
         else if (command == "RemoveLastAlbum") {
            playlist.RemoveLastAlbum();

        } else if (command == "RemoveAlbumAt") {
            int P;
            cin >> P;
            playlist.RemoveAlbumAt(P);

        } else if (command == "PopAlbum") {
            playlist.PopAlbum();
        }
    }

    return 0;
}
