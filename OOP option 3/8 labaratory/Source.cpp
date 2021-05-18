#include "Pet.h"
#include "Dog.h"
#include "Cat.h"
#include "Fish.h"
#include <iostream>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	cout << "����� �������� �������� �� ������ �������?" << endl << "1. �����" << endl << "2. ������" << endl << "3. ����" << endl <<"(�������� 1-3):";
	int choise;
	cin >> choise;
	Pet* p;
	switch (choise)
	{
	case 1:
		p = new Cat();
		break;
	case 2:
		p = new Dog();
		break;
	case 3:
		p = new Fish();
		break;
	default:
		cout << "�� �� ������ ?" << endl;
		return 0;
	}
	cout << "���������� ��� ������ �������: ";
	char n[255];
	cin.ignore();
	cin.getline(n, 255);
	p->setName(n);
	p->play();
	delete p;
	return 0;
}