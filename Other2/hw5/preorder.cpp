#include <iostream>
using namespace std;

template <class T>
class TreeNode {
public:
    T data;
    TreeNode<T>* leftChild;
    TreeNode<T>* rightChild;
    TreeNode() : leftChild(nullptr), rightChild(nullptr) {}
    TreeNode(T val) : data(val), leftChild(nullptr), rightChild(nullptr) {}
};


template <class T>
void Visit(TreeNode<T>* t) {
    cout << t->data << " ";
}


template <class T>
void PreOrder(TreeNode<T>* t) {
    if (t != nullptr) {
        Visit(t);
        PreOrder(t->leftChild);
        PreOrder(t->rightChild);    
    }
}

int main() {

    TreeNode<char>* root = new TreeNode<char>('a');
    root->leftChild = new TreeNode<char>('b');
    root->rightChild = new TreeNode<char>('c');

    PreOrder(root);

    delete root->leftChild;
    delete root->rightChild;
    delete root;

}
