#include "Library.h"

Library::Library() {
	//присваивание по умолчанию
	char NAME[LNAME] = "Standart name";
	char STREET[STREET] = "Standart name";
	strcpy_s(name, NAME);
	strcpy_s(street,STREET);
	coust = 0;
	//вывод
	show();
	cout << "Xoroshaya RABOTA maxim" << endl;
}

Library::Library(char* NAME, char* STREET_NAME, int COUST) {
	//присваивание переданных значений
	strcpy_s(name, NAME);
	strcpy_s(street, STREET_NAME);
	coust = COUST;
	//вывод
	show();
	cout << "Velikolepno" << endl;
}

Library::Library(const Library& LIBRARY) {
	//копирование
	strcpy_s(name, LIBRARY.name);
	strcpy_s(street, LIBRARY.street);
	coust = LIBRARY.coust;
	//вывод
	show();
	cout << "Xoroshaya rabota MAXIM" << endl;
}

Library::~Library() {
	//удаление
	show();
	//вывод
	cout << "Xoroshego Ydalenive" << endl;
}

char* Library::getName() {
	return name;
}
char* Library::getstreet() {
	return street;
}
int Library::getCoust() {
	return coust;
}
void Library::setName(char* NAME) {
	strcpy_s(name, NAME);
}
void Library::setstreet(char* STREET_NAME) {
	strcpy_s(street, STREET_NAME);
}
void Library::setCoust(int COUST) {
	coust = COUST;
}
void Library::set(char* NAME, char* STREET_NAME, int COUST) {
	strcpy_s(name, NAME);
	strcpy_s(street, STREET_NAME);
	coust = COUST;
}
void Library::show() {
	cout << "Name: " << name << endl;
	cout << "Street name: " << street << endl;
	cout << "coust: " << coust << endl;
}
