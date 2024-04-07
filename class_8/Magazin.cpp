#include "Magazin.h"
using namespace std;

void Magazin::Show(bool only_name){
	Print::Show(only_name);
	if (only_name == false) {
		cout << ". Количество страниц: " << number_of_pages;
	}
}

void Magazin::Input(){
	Print::Input();
	cout << "Введите количество страниц: ";
	cin >> number_of_pages;
}

void Magazin::set_pages(int pages) {
	number_of_pages = pages;
}

int Magazin::get_pages() {
	return number_of_pages;
}

Magazin& Magazin::operator=(Magazin& another) {
	Print::operator=(another);
	number_of_pages = another.number_of_pages;
	return *this;
}