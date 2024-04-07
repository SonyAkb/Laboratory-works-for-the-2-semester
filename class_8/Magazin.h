#pragma once //������������� ��������� �������� ������������� �����, ���� �� ��� ��� �������
#include <iostream> //����������� ������ ����� � ������
#include <string>
#include "Print.h"
using namespace std;

class Magazin : public Print {
public:
	int number_of_pages;
	Magazin() : Print() {}//����������� ��� ����������
	Magazin(string author, string name, int pages) : Print(author, name) {
		set_pages(pages);
	}

	void Show(bool only_name = false) override;
	void Input() override;
private:
	void set_pages(int pages);
	int get_pages();
	Magazin& operator=(Magazin& another);
};