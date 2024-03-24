#pragma once //������������� ��������� �������� ������������� �����, ���� �� ��� ��� �������
#include <iostream> //����������� ������ ����� � ������
using namespace std;

class Progression { //���������� ������ Progression
private: //���������� private ����� ������ Progression
	double first;//��������� private ���� first ���� double
	double second;//��������� private ���� second ���� double
public://���������� public ������� ������ Progression.
	Progression(double, double); //��������� ����������� ������ Progression, ������� ��������� ��� double ���������.
	double element(int); //��������� ����� element(), ������� ��������� int �������� � ���������� double ��������.
	void setFirst(double);//��������� ����� setFirst(), ������� ��������� double ��������.
	void setSecond(double); //��������� ����� setSecond(), ������� ��������� double ��������.
};