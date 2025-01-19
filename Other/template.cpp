#include <bits/stdc++.h>
using namespace std;

template <typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
// void mySwap(auto &a, auto &b) {
// auto temp = a;
// a = b;
// b = temp;
// }
int main() {
	int intA = 10, intB = 20;
	cout << "Before (int): A = " << intA << ", B = " << intB << "\n";
	mySwap(intA, intB);
	cout << "After (int): A = " << intA << ", B = " << intB << "\n";

	char charA = 'X', charB = 'Y';
	cout << "Before (char): A = " << charA << ", B = " << charB << "\n";
	mySwap(charA, charB);
	cout << "After (char): A = " << charA << ", B = " << charB << "\n";

	float floatA = 1.5, floatB = 2.5;
	cout << "Before (float): A = " << floatA << ", B = " << floatB << "\n";
	mySwap(floatA, floatB);
	cout << "After (float): A = " << floatA << ", B = " << floatB << "\n";
}
