#include <iostream>
#include "Time.h" 
using namespace std;

int main()
{
    Time t(19, 7, 6); 
    cout << "Universal time: ";
    t.printUniversal(); 
    cout << "\nStandard time: ";
    t.printStandard(); 

    cout << endl;
    return 0;
}
