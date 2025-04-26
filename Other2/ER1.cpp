#include <iostream>
using namespace std;

const int MAX = 10010;

int m, n, a, b;
int idx[MAX]; // 儲存目前列的欄號順序
int colSize[MAX]; // 每一欄目前的非零元素數量
int rowPos[MAX][MAX]; // 儲存轉置後的行號
int valPos[MAX][MAX]; // 儲存轉置後的數值
bool colUsed[MAX]; // 標記哪些欄有出現過

int main() {
    while (cin >> m >> n) {
        // 初始化
        for (int i = 0; i <= n; ++i) {
            colSize[i] = 0;
            colUsed[i] = false;
        }

        // 讀入原始稀疏矩陣，並建構轉置矩陣的資料
        for (int i = 1; i <= m; i++) {
            cin >> a; // 這一列有 a 個非零元素
            for (int j = 0; j < a; j++) {
                cin >> idx[j]; // 欄號
                colUsed[idx[j]] = true;
            }
            for (int j = 0; j < a; j++) {
                cin >> b; // 對應的值
                int col = idx[j];
                int k = colSize[col]++;
                rowPos[col][k] = i; // 原本的行號，現在變成欄
                valPos[col][k] = b; // 對應值
            }
        }

        // 輸出轉置後的結果
        cout << n << " " << m << "\n";

        for (int i = 1; i <= n; i++) {
            if (!colUsed[i]) {
                cout << "0\n\n";
                continue;
            }

            cout << colSize[i];
            for (int j = 0; j < colSize[i]; j++) {
                cout << " " << rowPos[i][j];
            }
            cout << "\n";

            cout << valPos[i][0];
            for (int j = 1; j < colSize[i]; j++) {
                cout << " " << valPos[i][j];
            }
            cout << "\n";
        }
    }
}
