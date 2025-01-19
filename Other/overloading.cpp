#include <iostream>
#include <string>
using namespace std;

void eat(int foodCount, const string& foodName) {
    cout << "Eating " << foodCount << " of " << foodName << endl;
}

void eat(const string& foodName, int foodCount) {
    cout << "Eating " << foodName << " in quantity: " << foodCount << endl;
}

int main() {
    eat(3, "Apples");         // 调用第一个 eat
    eat("Bananas", 5);        // 调用第二个 eat
    return 0;
}
