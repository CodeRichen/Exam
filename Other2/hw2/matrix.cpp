#include "matrix.h"

M::M(int r, int c) : row(r), col(c), num(0) {
  a1.resize(r, vector<int>(c, 0));
  a2.resize(c, vector<int>(r, 0));
}

void M::insert(int r, int c, int v) {
  t1.push_back({r, c, v});
  num++;
}

void M::result() {
  for (auto& t : t2) {
    printf("(%d, %d, %d) becomes (%d, %d, %d) in the transpose\n", t.row, t.col, t.val, t.col, t.row, t.val);
  }
}

void M::time() {
  chrono::duration<double> timer = end - start;

  cout << "Transpose time: " << timer.count() * 1000 << " ms" << endl;
}

T1::T1(int r, int c) : M(r, c) {}

void T1::insert(int r, int c, int v) {
  a1[r][c] = v;
  M::insert(r, c, v);
}

void T1::transpose() {
  start = chrono::high_resolution_clock::now();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      a2[j][i] = a1[i][j];
    }
  }
  end = chrono::high_resolution_clock::now();
  t2.clear();
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      if (a2[i][j] != 0) {
        t2.push_back({i, j, a2[i][j]});
      }
    }
  }
}
void T1::result(){
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout<<a1[i][j]<<" ";
        }
        cout<<"\n";
      }
cout<<"becomes"<<"\n";
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
          cout<<a2[i][j]<<" ";
        }
        cout<<"\n";
      }
}
T2::T2(int r, int c) : M(r, c) {}

void T2::transpose() {
  start = chrono::high_resolution_clock::now();
  for (auto t : t1) t2.push_back({t.col, t.row, t.val});
  end = chrono::high_resolution_clock::now();
}

T3::T3(int r, int c) : M(r, c) {}

void T3::transpose() {

  start = chrono::high_resolution_clock::now();
  vector<int> rN(col, 0), rS(col, 0);
  t2.resize(num);
  for (auto t : t1){ rN[t.col]++;
}
  for (int i = 1; i < col; i++) {
    rS[i] = rS[i - 1] + rN[i - 1];
  }
  for (auto t : t1) {
    t2[rS[t.col]] = {t.col, t.row, t.val};
    rS[t.col]++;
  }
  end = chrono::high_resolution_clock::now();
}
