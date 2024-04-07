#pragma once //������������� ��������� �������� ������������� �����, ���� �� ��� ��� �������
#include <iostream> //����������� ������ ����� � ������
using namespace std;

class Pair {
	int first;
	double second;

public:
	Pair();//����������� ������ �� ���������
	Pair(int, double);//����������� ������ � �����������
	Pair(const Pair&);//����������� ����������� ������
	~Pair();//���������� ������
	void Print();

	Pair operator+(Pair& p);
	Pair operator-(const Pair& para);
	void setFirst(const int& x);
	void setSecond(const double& y);
	int getFirst();
	double getSecond();
	void operator=(const Pair& para);
	friend ostream& operator <<(ostream& stream, const Pair& p);
	friend istream& operator >>(istream& stream, Pair& p);
	bool operator >(const Pair& p);
	bool operator <(const Pair& p);
	friend bool operator==(const Pair& a, const Pair& b);
	void operator/(const int& x);
	friend bool operator<(const Pair& a, const Pair& b);
	friend bool operator>(const Pair& a, const Pair& b);
};