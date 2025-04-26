class SparseMatrix {
    // ... 其他成員同上 ...

    // 加法
    SparseMatrix Add(SparseMatrix& b) {
        if (rows != b.rows || cols != b.cols) throw std::runtime_error("Dimension mismatch");
        SparseMatrix result(rows, cols);
        MatrixNode* a = head->next;
        MatrixNode* b_ptr = b.head->next;
        while (a || b_ptr) {
            if (!b_ptr || (a && a->row < b_ptr->row) || 
                (a && a->row == b_ptr->row && a->col < b_ptr->col)) {
                result.addElement(a->row, a->col, a->value);
                a = a->next;
            } else if (!a || a->row > b_ptr->row || 
                       (a->row == b_ptr->row && a->col > b_ptr->col)) {
                result.addElement(b_ptr->row, b_ptr->col, b_ptr->value);
                b_ptr = b_ptr->next;
            } else { // 相同位置
                int sum = a->value + b_ptr->value;
                if (sum != 0) result.addElement(a->row, a->col, sum);
                a = a->next;
                b_ptr = b_ptr->next;
            }
        }
        return result;
    }

    // 乘法
    SparseMatrix Multiply(SparseMatrix& b) {
        if (cols != b.rows) throw std::runtime_error("Dimension mismatch");
        SparseMatrix result(rows, b.cols);
        for (MatrixNode* a = head->next; a; a = a->next) {
            for (MatrixNode* b_ptr = b.head->next; b_ptr; b_ptr = b_ptr->next) {
                if (a->col == b_ptr->row) {
                    result.addElement(a->row, b_ptr->col, a->value * b_ptr->value);
                }
            }
        }
        return result;
    }
};

// 複數矩陣乘法
void complexMatrixMultiply(SparseMatrix& A, SparseMatrix& B, SparseMatrix& C, SparseMatrix& D,
                          SparseMatrix& real_result, SparseMatrix& imag_result) {
    SparseMatrix AC = A.Multiply(C);
    SparseMatrix BD = B.Multiply(D);
    SparseMatrix AD = A.Multiply(D);
    SparseMatrix BC = B.Multiply(C);

    SparseMatrix neg_BD = BD;
    for (MatrixNode* p = neg_BD.head->next; p; p = p->next) p->value = -p->value;
    real_result = AC.Add(neg_BD);
    imag_result = AD.Add(BC);
}