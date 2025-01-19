#include <iostream>
#include <string>
#include "TrieTree.h"

using namespace std;

TrieNode::TrieNode() {
    for (int i = 0; i < 26; i++) {
        child[i] = NULL; //陣列當中每一個人元素 都是一class 
    }
    isWord = false;
}

TrieTree::TrieTree() {
    root = new TrieNode();
}

void TrieTree::insert(string word) {
    TrieNode* current = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (current->child[index] == NULL) {
            current->child[index] = new TrieNode();
        }
        current = current->child[index];
    }
    current->isWord = true;
}

bool TrieTree::search(string word) {
    TrieNode* current = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (current->child[index] == NULL) {
            return false;
        }
        current = current->child[index];
    }
    return current->isWord;
}

bool TrieTree::startsWith(string prefix) {
    TrieNode* current = root;
    for (int i = 0; i < prefix.length(); i++) {
        int index = prefix[i] - 'a';
        if (current->child[index] == NULL) {
            return false;
        }
        current = current->child[index];
    }
    return true;
}
/*
root
 └── a
     └── p
         └── p
             └── l
                 ├── e (isWord = true)
                 └── a (isWord = true)
*/