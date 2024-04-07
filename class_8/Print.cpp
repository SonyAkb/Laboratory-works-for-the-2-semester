#include "Print.h"
using namespace std;

Print::Print(string author, string name) {//����������� � �����������
		set_author(author);
		set_name(name);
}

string Print::get_author() {//��������� ����� ������
	return Author;
}
string Print::get_name() {//��������� ��������
	return Name;
}

void Print::set_author(string author) {//��������� ������
	Author = author;
}
void Print::set_name(string name) {//��������� ��������
	Name = name;
}

void Print::Show(bool only_name){//����� ������
	if (only_name == false) {
		cout << "�����: " << this->get_author() << ". ";
	}
	cout << "��������: " << this->get_name();
}
void Print::Input(){
	cin.ignore();
	cout << "������� ��� ������: ";
	getline(cin, Author);
	cout << "������� ��������: ";
	getline(cin, Name);
}

Print& Print::operator=(Print& another) {
	Author = another.Author;
	Name = another.Name;
	return *this;
}