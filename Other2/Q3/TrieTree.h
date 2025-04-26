#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode* child[26];
    bool isWord;
    TrieNode();
};

class TrieTree {
public:
    TrieTree() ;
    void insert(string);
    bool search(string);
    bool startsWith(string);
private:
    TrieNode* root;
};