#include "Date.h"
#include <iostream>

using namespace std;

int main(){
    Date d1;
    d1.nextDay();
    int n;
    cin>>n;
    while (n--)
    {
        int m, d, y;
        cin>>y>>m>>d;
        d1.setY(y).setM(m).setD(d);
        d1.nextDay();
    }
    
}