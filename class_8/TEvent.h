#pragma once //������������� ��������� �������� ������������� �����, ���� �� ��� ��� �������

using namespace std;

const int CM_create_a_group = 1; //m ������� ������
const int CM_Add_to_a_group = 2; //+ �������� � ������ ��������
const int CM_Remove_from_the_group = 3; //- ������� ������� �� ������
const int CM_Print = 4; //s	������� ���������� �� ��������� ����
const int CM_inform_all_el_of_the_group = 5; //z ������� ���������� � ��������� ���� ��������� ������ 
const int CM_Quit = 6; //q ����� ������ 

const int EV_Nothing = 0; //����� ������
const int EV_Message = 100; //


class TEvent {
public:
	int what; //��� �������
	int Command;
};