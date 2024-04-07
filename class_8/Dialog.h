#pragma once //������������� ��������� �������� ������������� �����, ���� �� ��� ��� �������
#include <iostream> //����������� ������ ����� � ������
#include <string>
#include "VECTOR.h"
#include "TEvent.h"
#include "Magazin.h"
using namespace std;

class Dialog : public VECTOR {
private:
	bool end_of_work = false;//���� �� ��������� ������
public:
	Dialog();//����������� ��� ����������
	~Dialog() {};//����������
	void Execute();
	void Get_Event(TEvent& event);//������ �������
	void Handle_Event(TEvent& Event);//������� �������
	void ClearEvent(TEvent& event); //������ ������� �������
	void choosing_an_action();
protected:
	bool End_State;
};