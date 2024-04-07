#include "Print.h"
using namespace std;

Print::Print(string author, string name) {//конструктор с параметрами
		set_author(author);
		set_name(name);
}

string Print::get_author() {//получение имени автора
	return Author;
}
string Print::get_name() {//получение названи€
	return Name;
}

void Print::set_author(string author) {//установка автора
	Author = author;
}
void Print::set_name(string name) {//установка названи€
	Name = name;
}

void Print::Show(bool only_name){//вывод данных
	if (only_name == false) {
		cout << "јвтор: " << this->get_author() << ". ";
	}
	cout << "Ќазвание: " << this->get_name();
}
void Print::Input(){
	cin.ignore();
	cout << "¬ведите им€ автора: ";
	getline(cin, Author);
	cout << "¬ведите название: ";
	getline(cin, Name);
}

Print& Print::operator=(Print& another) {
	Author = another.Author;
	Name = another.Name;
	return *this;
}