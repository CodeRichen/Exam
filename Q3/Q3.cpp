#include <iostream>
#include <string>
#include "TrieTree.h"

using namespace std;

int main(){
    int n;
    cin>>n;
    TrieTree t;
    while (n--){
        string command, word;
        cin>>command>>word;
        if(command == "INSERT"){
            t.insert(word);
        }else if(command == "SEARCH"){
            cout<<(t.search(word)? "true" : "false")<<endl;
        }else if(command == "startsWith"){
            cout<<(t.startsWith(word)? "true" : "false")<<endl;
        }
    }
    
}