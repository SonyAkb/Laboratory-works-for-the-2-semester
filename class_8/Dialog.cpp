#include "Dialog.h"
using namespace std;

Dialog::Dialog() {
	end_of_work = false;
}

void Dialog:: Execute() {
	TEvent Event;
	while (!end_of_work) {
		Get_Event(Event);
		Handle_Event(Event);
	}
}

void Dialog::Get_Event(TEvent& event) {
	choosing_an_action();

	string str;
	cout << ">  ";
	cin >> str;
	char CM_symbol = str[0];//���� ������ ������
	cout << "���� �������: " << CM_symbol << endl << endl;

	event.what = EV_Message;
	switch (CM_symbol) {
	case 'm'://m ������� ������
		event.Command = CM_create_a_group;
		break;
	case '+'://+ �������� � ������ ��������
		event.Command = CM_Add_to_a_group;
		break;
	case '-'://- ������� ������� �� ������
		event.Command = CM_Remove_from_the_group;
		break;
	case 's'://s	������� ���������� �� ��������� ����
		event.Command = CM_Print;
		break;
	case 'z'://z ������� ���������� � ��������� ���� ��������� ������ 
		event.Command = CM_inform_all_el_of_the_group;
		break;
	case 'q'://q ����� ������ 
		event.Command = CM_Quit;
		break;
	default://����� ��������
		event.Command = EV_Nothing;
	}
}

void Dialog::Handle_Event(TEvent& Event) {
	if (Event.Command == EV_Nothing) {
		cout << "����� ������� ���!" << endl;
	}
	else {
		int size;
		string NName;
		switch (Event.Command) {//����� ��������
		case CM_create_a_group:
			do {
				cout << "������� ������: ";
				cin >> size;
			} while (size <= 0);
			RE_create(size);
			break;
		case CM_Add_to_a_group:
			Add();
			break;
		case CM_Remove_from_the_group:
			Del();
			break;
		case CM_Print:
			print();
			cout << endl;
			break;
		case CM_inform_all_el_of_the_group:
			print(true);
			cout << endl;
			break;
		case CM_Quit:
			end_of_work = true;
			break;
		default:
			break;
		}
		ClearEvent(Event);
	}
}

void Dialog::ClearEvent(TEvent& event) {
	event.what = EV_Nothing;
}

void Dialog::choosing_an_action() {
	cout << "---------------------------------------------------------" << endl;
	cout << "��� �� ������ �������?" << endl;
	cout << "m:   ������� ������" << endl;
	cout << "+:   �������� ������� � ������" << endl;
	cout << "-:   ������� ������� �� ������" << endl;
	cout << "s:   ������� ���������� �� ��������� ������" << endl;
	cout << "z:   ������� ���������� � ��������� ���� ��������� ������" << endl;
	cout << "q:   ����� ������" << endl;
}