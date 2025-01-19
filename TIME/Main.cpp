#include <iostream>
#include "Date.h"
using namespace std;

int main() {
    Date date(12, 30, 2023);
    for (int i = 0; i < 5; ++i) {
        date.print();
        cout << endl;
        date.nextDay();
    }

    return 0;
}
