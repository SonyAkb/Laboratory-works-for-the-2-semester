#pragma once //������������� ��������� �������� ������������� �����, ���� �� ��� ��� �������
#include <iostream> //����������� ������ ����� � ������
#include <string>

using namespace std;

class Object {
public:
	Object() {}; //�����������
	virtual ~Object() {};//����������
	virtual void Show(bool only_name = false) = 0;
	virtual void Input() = 0;
	virtual string get_name() = 0;
};