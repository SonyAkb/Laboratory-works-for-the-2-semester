#include <iostream>
#include "pair.h"

using namespace std;

int main() {
	system("chcp 1251 > Null");

	int number_1 = 5;
	double number_2 = 5.1;

	Pair a(3, 5);
	cout << "a = " << a << endl;
	Pair b(2, 8);
	cout << "b = " << b << endl;
	Pair c;
	cout << "c = " << c << endl;
	Pair d(a);
	cout << "d = " << d << endl << endl;

	c = b;
	cout << "c = " << c << endl << endl;
	a - b;
	cout << "Вычитание a - b: " << a << " - " << b << " = " << a << endl ;
	a + number_1;
	cout << "a + " << number_1 << " = " << a << endl;
	b + number_2;
	cout << "b + " << number_2 << " = " << b << endl;
}