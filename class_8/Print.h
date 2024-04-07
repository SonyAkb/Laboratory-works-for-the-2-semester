#pragma once //������������� ��������� �������� ������������� �����, ���� �� ��� ��� �������
#include <iostream> //����������� ������ ����� � ������
#include <string>
#include "Object.h"
using namespace std;

class Print : public Object {
protected:
	string Author;
	string Name;
public:
	Print() {};//����������� ��� ����������
	Print(string author, string name);//����������� � �����������
	virtual ~Print() {};//����������

	string get_author();//��������� ����� ������
	string get_name();//��������� ��������

	void set_author(string author);//��������� ������
	void set_name(string name);//��������� ��������
	void Show(bool only_name = false) override;//����� ������
	void Input() override;
	Print& operator=(Print& another);
};