#include <iostream>
#include <sstream>
using namespace std;

const int MAX = 100;

struct Position {
    int row, col, prevIdx;
};

class MazeSolver {
private:
    char maze[MAX][MAX], mark[MAX][MAX], pathSymbol[MAX][MAX];
    int rows = 0, cols = 0;
    int startR, startC, endR, endC;

    int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    char symbol[8] = { '|', '/', '-', '\\', '|', '/', '-', '\\' };

    Position queue[MAX * MAX];
    int front = 0, rear = 0;

    bool isLegal(int r, int c) {
        return r >= 0 && r < rows && c >= 0 && c < cols && maze[r][c] != 'b' && mark[r][c] == 0;
    }

    void printMaze() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << pathSymbol[i][j];
                if (j < cols - 1) cout << " ";
            }
            cout << endl;
        }
    }

public:
    void readMaze() {
        string line;
        while (getline(cin, line)) {
            if (line.empty()) break;
            istringstream iss(line);
            string token;
            int c = 0;
            while (iss >> token) {
                char ch = token[0];
                maze[rows][c] = ch;
                mark[rows][c] = 0;
                pathSymbol[rows][c] = ch;
                if (ch == 's') { startR = rows; startC = c; }
                if (ch == 'e') { endR = rows; endC = c; }
                c++;
            }
            cols = c;
            rows++;
        }
    }

    void solveMazeBFS() {
        mark[startR][startC] = 1;
        queue[rear++] = { startR, startC, -1 };

        int endIdx = -1;

        while (front < rear) {
            Position cur = queue[front++];

            for (int d = 0; d < 8; d++) {
                int nr = cur.row + dr[d], nc = cur.col + dc[d];
                if (nr == endR && nc == endC) {
                    endIdx = rear;
                    queue[rear++] = { nr, nc, front - 1 };
                    goto reconstruct;
                }
                if (isLegal(nr, nc)) {
                    mark[nr][nc] = 1;
                    queue[rear++] = { nr, nc, front - 1 };
                }
            }
        }

    reconstruct:
        if (endIdx == -1) {
            cout << "No path found." << endl;
            return;
        }

        int steps = 0;
        int cur = endIdx;
        pathSymbol[endR][endC] = 'e';

        while (queue[cur].prevIdx != -1) {
            int r = queue[queue[cur].prevIdx].row;
            int c = queue[queue[cur].prevIdx].col;
            int nr = queue[cur].row;
            int nc = queue[cur].col;

            for (int d = 0; d < 8; d++) {
                if (r + dr[d] == nr && c + dc[d] == nc) {
                    pathSymbol[r][c] = symbol[d];
                    steps++;
                    break;
                }
            }
            cur = queue[cur].prevIdx;
        }

        printMaze();
        cout << "Total " << steps << " Steps." << endl;
    }
};

int main() {
    MazeSolver solver;
    cout << "請輸入迷宮（每行用空格分隔，s 為起點，e 為終點，b 為牆，0 為可走）:\n(輸入空行結束)\n";
    solver.readMaze();
    solver.solveMazeBFS();
    return 0;
}
