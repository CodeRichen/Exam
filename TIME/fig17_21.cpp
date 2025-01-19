#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
    Date birth(7, 24, 1949);
    Date hire(3, 12, 1988);
    Date leave(8, 31, 2008);
    Employee manager("Bob", "Blue", birth, hire, leave);

    cout << endl;
    manager.print();
}
