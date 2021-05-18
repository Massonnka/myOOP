#pragma once
#ifndef Library_H_


#include <iostream>

using namespace std;

const int LNAME = 25;
const int STREET = 25;

class Library
{
private:
	// поля класса
	char name[LNAME];
	char street[STREET];
	int coust;

public:
	// конструкторы класса
	Library();
	Library(char*, char*, int);
	Library(const Library&);
	//конструкторы класса
	~Library();
	//деструктор класса
	char* getName();
	char* getstreet();
	int getCoust();
	void setName(char*);
	void setstreet(char*);
	void setCoust(int);
	void set(char*, char*, int);
	//метод для выведения данных
	void show();
};

#endif // !Libarary_H_
