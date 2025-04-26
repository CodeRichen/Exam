#include "matrix.h"

int main() {
  int r, c, v;
  cin >> r >> c;
  vector<M::T> D;
  T1 t1(r, c);
  T2 t2(r, c);
  T3 t3(r, c);
  while (cin >> r >> c >> v) {
    t1.insert(r, c, v);
    D.push_back({r, c, v});
  }
  cout<<"traditional 2-dimensional array representation:"<<"\n"<<"\n";
  t1.transpose();
  t1.time();
  t1.result();  
  cout<<"\n"<<"“Transpose” method in the textbook:"<<"\n"<<"\n";
  for (auto d : D) t2.insert(d.row, d.col, d.val);
  t2.transpose();
  t2.time();
  t2.result();
  cout<<"\n"<<"“FastTranspose” method in the textbook:"<<"\n"<<"\n";
  for (auto d : D)t3.insert(d.row, d.col, d.val);
  t3.transpose();
  t3.time();
  t3.result();
}
