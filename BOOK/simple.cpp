#include <bits/stdc++.h>
using namespace std;

class GradeBook {
 public:
  GradeBook(string name, string id) { set(name, id); }
  void set(string name, string id) {
    cname = name;
    cid = id;
  }
  string getname() { return cname; }
  string getid() { return cid; }
  void displayMessage() { cout << "welcome"; }

 private:
  string cname;
  string cid;
};

int main() {
  GradeBook GradeBook1("CS101 Introduction to C++ Programming", "A1125515");
  GradeBook GradeBook2("CS102 Data Structures in C++", "A1125515");
  cout << "gradeBook1 created for course: " << GradeBook1.getname() << "("
       << GradeBook1.getid() << ")"
       << "\ngradeBook2 created for course: " << GradeBook2.getname() << "("
       << GradeBook1.getid() << ")";
}
