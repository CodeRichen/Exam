#ifndef MATRIX_H
#define MATRIX_H

#include <bits/stdc++.h>
using namespace std;

class M {
 public:
  struct T {
    int row, col, val;
  };

 protected:
  int row, col, num;
  double timer;
  chrono::high_resolution_clock::time_point start, end;
  vector<T> t1, t2;
  vector<vector<int>> a1, a2;

 public:
  M(int r, int c);
  virtual void insert(int r, int c, int v);
  virtual void transpose() = 0;
  virtual void result();
  void time();
};

class T1 : public M {
 public:
  T1(int r, int c);
  void insert(int r, int c, int v) override;
  void transpose() override;
  void result() override;
};

class T2 : public M {
 public:
  T2(int r, int c);
  void transpose() override;
};

class T3 : public M {
 public:
  T3(int r, int c);
  void transpose() override;
};

#endif
