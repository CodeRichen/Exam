template <class T>
class ChainNode {
private:
    T data;              // 儲存資料
    ChainNode<T>* link;  // 指向下一個節點
    // 構造函數
    ChainNode() {}
    ChainNode(const T& data) : data(data), link(nullptr) {}
    ChainNode(const T& data, ChainNode<T>* link) : data(data), link(link) {}
};

template<class T>
class Chain {
public:
    Chain() : first(nullptr) {} // 空鏈
    ~Chain();                   // 釋放節點
    bool IsEmpty() const { return first == nullptr; }
private:
    ChainNode<T>* first;        // 指向第一節點
};