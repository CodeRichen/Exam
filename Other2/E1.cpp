#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int m, n, a, b;
vector<int> idx;  // 暫存目前列的欄號順序
map<int, vector<pair<int, int>>> mp; // mp[欄號] = vector< (行號, 值) >
set<int> st; // 記錄所有出現過的欄號，用於轉置時排序輸出

int main() {
    // 支援多組輸入
    while (cin >> m >> n) {
        mp.clear(); // 清空上一組資料
        st.clear();

        // 逐列輸入 m 行
        for (int i = 1; i <= m; i++) {
            cin >> a; // 目前列中非零元素數量
            idx.clear();
            for (int j = 0; j < a; j++) {
                cin >> b; // 欄號
                idx.push_back(b);
                mp[b].push_back({i, 0}); // 初始值先設為 0，之後補上
                st.insert(b); // 紀錄出現過的欄號
            }
            for (int j = 0; j < a; j++) {
                cin >> b; // 對應欄號的值
                mp[idx[j]].back().second = b;
            }
        }

        // 輸出轉置後的矩陣：行列對調
        cout << n << " " << m << "\n";

        int pre = 0; // 前一個列號，用來補零列
        for (auto i : st) {
            pre++;
            // 補上中間沒有出現的欄位（等價於轉置後為空的列）
            while (pre < i) {
                cout << "0\n\n";
                pre++;
            }

            // 輸出欄號 i 對應的資料
            cout << mp[i].size(); // 非零元素數量
            for (int j = 0; j < mp[i].size(); j++) {
                cout << " " << mp[i][j].first; // 行號（原本的列）
            }
            cout << "\n";

            // 輸出實際數值
            cout << mp[i][0].second;
            for (int j = 1; j < mp[i].size(); j++) {
                cout << " " << mp[i][j].second;
            }
            cout << "\n";
        }

        // 若最後幾列完全沒出現，補空列
        while (pre < n) {
            cout << "0\n\n";
            pre++;
        }
    }
}
