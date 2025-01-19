#include <iostream>
#include "Class.h"
using namespace std;

int main() {
    int q, a, z, w, s, x;
    cin >> w;
    Date date(2, 1, 2000);
    for (s = 0; s < w; s++) {
        cin >> q >> a >> z;
        date.setY(q);
        date.setM(a);
        date.setD(z);
        date.nextDay();
    }
    return 0;
}
