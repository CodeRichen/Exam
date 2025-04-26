#include <iostream>
#include <sstream>
using namespace std;

#define k 100

struct p{
    int r,c,d;
};
template<class T>
class s{
    public: 
    T* arr;
    int c,a;
    s(int size=1000){
        c=size;
        arr =new T[c];
        c=-1;
    }
    ~s(){
        delete[] arr;
    }
    void pop(){
        c-=1;
    }
    void push(const T& a){
        c+=1;
        arr[c]=a;
    } 
    bool empty(){
        return c==-1;
    }
    T top(){
        return arr[c];
    }
};

char m1[k][k], m3[k][k];
bool m2[k][k]; 
int r = 0, c = 0;
int sr, sc, er, ec;
// int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };//-1 y-1 往上
// int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };//1 x+1 往右
// char symbol[8] = { '|', '/', '-', '\\', '|', '/', '-', '\\' };
int dr[8] = { 0, -1,  1,  0, -1,-1,1,1 };//-1 y-1 往上
int dc[8] = { 1, 0,  0,  -1, -1 ,1,1,-1};//1 x+1 往右
char symbol[8] = { '-', '|', '|', '-', '\\' , '/', '\\', '/'};

int main() {
    string q;
    while (getline(cin, q)) {
        if (q.empty()) break;
        c = 0;
        for (int i = 0; i < q.size(); i++) {
            if (q[i] == ' ') continue;
            char z = q[i];
            m1[r][c] = z;
            m2[r][c] = false;
            m3[r][c] = z;
            if (z == 's') { sr = r; sc = c; }
            if (z == 'e') { er = r; ec = c; }
            c++;
        }
        r++;
    }

    int row = r, col = c;
    s<p> stk;
    m2[sr][sc] = true;
    stk.push({ sr, sc, 0 });

    bool found = false;

    while (!stk.empty() && !found) {
        p p1 = stk.top();
        stk.pop();
        int r = p1.r, c = p1.c, d = p1.d;

        while (d < 8 && !found) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr == er && nc == ec) {
                // m3[r][c] = symbol[d];
                stk.push({ r, c, d + 1 });
                nr=-1;nc=-1;
                while(!stk.empty()){
                    p b=stk.top();
                    // cout<<b.r<<b.c<<symbol[b.d-1]<<"\n";
                    // m3[b.r][b.c]=symbol[b.d-1];
                    if (nr!=-1)m3[nr][nc]=symbol[b.d-1];
                   nr=b.r;nc=b.c;
                    stk.pop();
                    
                }
                found = true;
                break;
            }

            if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                m1[nr][nc] != 'b' && !m2[nr][nc]) {
                m2[nr][nc] = true;
                stk.push({ r, c, d + 1 });
                r = nr; c = nc; d = 0;
            } else {
                d++;
            }
        }
    }

    if (found) {
        int v = 1;
        // int v=0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << m3[i][j];
                if (j < col - 1) cout << " ";
                if (m3[i][j] == '-' || m3[i][j] == '|' || m3[i][j] == '/' || m3[i][j] == '\\')
                    v++;
                // if(i==sr and j==sc)cout<<'s'
            }
            cout << endl;
        }
        cout << "Total " << v << " Steps." << endl;
    }

    return 0;
}
