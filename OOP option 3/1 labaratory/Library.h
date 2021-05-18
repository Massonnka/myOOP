#pragma once
#ifndef Library_H_


#include <iostream>

using namespace std;

const int LNAME = 25;
const int STREET = 25;

class Library
{
private:
	// ���� ������
	char name[LNAME];
	char street[STREET];
	int coust;

public:
	// ������������ ������
	Library();
	Library(char*, char*, int);
	Library(const Library&);
	//������������ ������
	~Library();
	//���������� ������
	char* getName();
	char* getstreet();
	int getCoust();
	void setName(char*);
	void setstreet(char*);
	void setCoust(int);
	void set(char*, char*, int);
	//����� ��� ��������� ������
	void show();
};

#endif // !Libarary_H_
