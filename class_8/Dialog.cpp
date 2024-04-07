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
	char CM_symbol = str[0];//беру первый символ
	cout << "Ваша команда: " << CM_symbol << endl << endl;

	event.what = EV_Message;
	switch (CM_symbol) {
	case 'm'://m создать группу
		event.Command = CM_create_a_group;
		break;
	case '+'://+ добавить в группу элемента
		event.Command = CM_Add_to_a_group;
		break;
	case '-'://- удалить элемент из группы
		event.Command = CM_Remove_from_the_group;
		break;
	case 's'://s	Вывести информацию об элементах груп
		event.Command = CM_Print;
		break;
	case 'z'://z Вывести информацию о названиях всех элементов группы 
		event.Command = CM_inform_all_el_of_the_group;
		break;
	case 'q'://q Конец работы 
		event.Command = CM_Quit;
		break;
	default://левое значение
		event.Command = EV_Nothing;
	}
}

void Dialog::Handle_Event(TEvent& Event) {
	if (Event.Command == EV_Nothing) {
		cout << "Такой команды нет!" << endl;
	}
	else {
		int size;
		string NName;
		switch (Event.Command) {//выбор действия
		case CM_create_a_group:
			do {
				cout << "Введите размер: ";
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
	cout << "Что вы хотите сделать?" << endl;
	cout << "m:   Создать группу" << endl;
	cout << "+:   Добавить элемент в группу" << endl;
	cout << "-:   Удалить элемент из группы" << endl;
	cout << "s:   Вывести информацию об элементах группы" << endl;
	cout << "z:   Вывести информацию о названиях всех элементов группы" << endl;
	cout << "q:   Конец работы" << endl;
}