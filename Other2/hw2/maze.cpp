#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 100;

// 方向：東、南、西、北
int dirRow[] = {0, 1, 0, -1};
int dirCol[] = {1, 0, -1, 0};

struct Position {
    int i, j, dir;
};

bool solveMaze(vector<vector<int>>& maze, int m, int n) {
    vector<vector<int>> mark(m, vector<int>(n, 0));
    stack<Position> path;

    Position start = {1, 1, 0};
    path.push(start);
    mark[1][1] = 1;

    while (!path.empty()) {
        Position current = path.top();
        path.pop();

        int i = current.i;
        int j = current.j;
        int d = current.dir;

        while (d < 4) {
            int g = i + dirRow[d];
            int h = j + dirCol[d];

            if (g == m - 2 && h == n - 2 && maze[g][h] == 0) {
                // 找到出口
                cout << "成功找到出口路徑！" << endl;

                // 將整個路徑列印出來（包含終點）
                path.push({i, j, d});
                while (!path.empty()) {
                    auto p = path.top();
                    path.pop();
                    cout << "(" << p.i << "," << p.j << ") -> ";
                }
                cout << "(" << g << "," << h << ")" << endl;
                return true;
            }

            if (maze[g][h] == 0 && mark[g][h] == 0) {
                mark[g][h] = 1;
                path.push({i, j, d + 1});
                i = g;
                j = h;
                d = 0;
            } else {
                d++;
            }
        }
    }

    cout << "找不到出口路徑！" << endl;
    return false;
}

int main() {
    int m = 8, n = 8;
    vector<vector<int>> maze = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1}
    };

    solveMaze(maze, m, n);

    return 0;
}
