#include <bits/stdc++.h>
using namespace std;
void swap1(int* a, int* b);
void swap2(int& a, int& b);
int main() {
	int a = 1;
	int b = 2;
	cout << "a=" << a << ";b=" << b << endl;
	swap1(&a, &b);
	cout << "a=" << a << ";b=" << b << endl;
	swap2(a, b);
	cout << "a=" << a << ";b=" << b << endl;
	
}
void swap1(int* a, int* b) {
	
	int tmp = *b;
	*b = *a;
	*a = tmp;
	
}
void swap2(int& a, int& b) {
	int tmp = b;
	b = a;
	a = tmp;
}
