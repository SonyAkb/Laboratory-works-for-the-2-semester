#pragma once //������������� ��������� �������� ������������� �����, ���� �� ��� ��� �������
#include <iostream> //����������� ������ ����� � ������
using namespace std;

class Pay { //���������� ������ Pay
	string name;//���
	double salary;//�/�
	int bonus;//������
public:
	Pay(); //����������� ������ Pay �� ���������
	Pay(string, double, int); //����������� ������ Pay � �����������
	Pay(const Pay&);//����������� ����������� ������ Pay 
	~Pay();//���������� ������ Pay

	string get_Name();//���������� ���
	void set_Name(string);//���������� ���
	double get_Salary();//���������� �/�
	void set_Salary(double);//���������� �/�
	int get_Bonus();//���������� ������
	void set_Bonus(int);//���������� ������
	void Print(); //����� ���������� ������
};