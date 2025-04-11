struct MatrixNode {
    int row, col, value;
    MatrixNode* next;
    MatrixNode(int r, int c, int v) : row(r), col(c), value(v), next(nullptr) {}
};

class SparseMatrix {
private:
    int rows, cols, terms; // 行數、列數、非零元素數
    MatrixNode* head;      // 鏈結串列頭節點（虛擬節點）
public:
    SparseMatrix(int r, int c) : rows(r), cols(c), terms(0), head(new MatrixNode(-1, -1, 0)) {}
    ~SparseMatrix() {
        MatrixNode* current = head;
        while (current) {
            MatrixNode* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // 添加元素
    void addElement(int r, int c, int v) {
        if (r >= rows || c >= cols) throw std::out_of_range("Invalid position");
        if (v == 0) return; // 忽略零值
        MatrixNode* newNode = new MatrixNode(r, c, v);
        MatrixNode* current = head;
        while (current->next && (current->next->row < r || 
               (current->next->row == r && current->next->col < c))) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        terms++;
    }

    // 轉置
    SparseMatrix Transpose() {
        SparseMatrix result(cols, rows); // 行列互換
        MatrixNode* current = head->next;
        while (current) {
            result.addElement(current->col, current->row, current->value);
            current = current->next;
        }
        return result;
    }
};