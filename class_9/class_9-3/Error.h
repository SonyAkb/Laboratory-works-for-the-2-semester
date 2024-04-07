#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error{
public:
	virtual void what() {};
};
//----------------------------------
class Index_Error: public Error {
protected:
	string message_1;
public:
	Index_Error() {
		message_1 = "Ќедопустимый индекс списка!";
	}
	virtual void what() {
		cout << message_1 << endl;
	}
};

class error_index_is_too_small : public Index_Error {
	string message_2;
public:
	error_index_is_too_small() {
		Index_Error();
		message_2 = "ќтрицательный индекс недопустим.";
	}
	virtual void what() {
		cout << message_1 << " " << message_2 << endl << endl;
	}
};

class error_index_is_too_big : public Index_Error {
	string message_2;
public:
	error_index_is_too_big() {
		Index_Error();
		message_2 = "»ндекс больше текущего размера списка.";
	}
	virtual void what() {
		cout << message_1 << " " << message_2 << endl << endl;
	}
};

//--------------------

class Size_Error : public Error {
protected:
	string message_1;
public:
	Size_Error() {
		message_1 = "Ќедопустимый размер списка!";
	}
	virtual void what() {
		cout << message_1 << endl;
	}
};

class error_size_is_too_small : public Size_Error {
	string message_2;
public:
	error_size_is_too_small() {
		Index_Error();
		message_2 = "ќтрицательный рамер недопустим.";
	}
	virtual void what() {
		cout << message_1 << " " << message_2 << endl << endl;
	}
};

class error_size_is_too_big : public Size_Error {//как будто бы не нужно
	string message_2;
public:
	error_size_is_too_big() {
		Index_Error();
		message_2 = "ѕревышен максимальный размер.";
	}
	virtual void what() {
		cout << message_1 << " " << message_2 << endl << endl;
	}
};