#include <string.h>
#include <iostream>
#include <tchar.h>

using namespace std;

template <class T>
class Array
{
private:
	T* mass;
	int size;
	int index;

	int find(char sym) {
		for (int i = 0; i < size; i++) {
			if (this->setChar[i] == sym) {
				return i;
			}
		}

		return -1;
	}
public:
	Array(int n = 0);               //конструктор по умолчанию
	~Array() {
		if (mass) {
			delete[] mass;
		}
	}                                   //деструктор
	Array(const Array& tam);            //конструктор копирования
	T& operator = (Array& tam);			//перегрузка операции присваивания
	bool operator != (Array& tam);		//перегрузка операции на неравенство
	const T& operator [] (int);         //перегрузка оператора индексирования
	void add();
	void show_list();                   //вывод на экран
};

template <class T>Array<T>::Array(int n) {
	size = n;
	index = 0;
	if (n)
	{
		mass = new T[size];
	}
	else
	{
		mass = 0;
	}
}

template<class T>Array<T>::Array(const Array& tam) {
	size = tam.size;
	index = 0;
	if (tam.mass)
	{
		mass = new T[size];
		for (int i = 0; i < size; i++)
		{
			mass[i] = tam.mass[i];
		}
	}
	else
	{
		mass = 0;
	}
}

template<class T>void Array<T>::show_list() {
	for (int i = 0; i < index; i++) {
		cout << mass[i] << " ";
	}
	cout << endl;
}

template<class T>const T& Array<T>::operator [] (int i) {
	if (i < size) {
		return mass[i];
	}
	else {
		cout << "Error" << endl;
		exit(1);
	}
}

template<class T>T& Array<T>::operator = (Array& tam) {
	if (&tam == this) return *this;//сравнение адресов
	if (mass) delete[] mass;
	size = tam.size;
	if (tam.mass) {
		mass = new T[size];
		for (int i = 0; i < size; i++) {
			mass[i] = tam.mass[i];
		}
	}
	else
		mass = 0;
	return *this;
}

template<class T>T& Array<T>::operator != (Array& tam) {
	for (int i = 0; i < this->size; i++) {
		if (tam.find(this->mass[i]) == -1) {
			return false;
		}
	}

	return true;
}

template<class T>void Array<T>::add() {
	T tamp;
	for (int i = 0; i < size; i++) {
		cout << "Введите значение: ";
		cin >> tamp;
		mass[i] = tamp;
		++index;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	Array<int>tam1(3);
	cout << "char pressed" << endl;
	tam1.add();

	Array<int>tam2(3);
	cout << "int pressed" << endl;
	tam2.add();

	Array<float>tam3(3);
	cout << "float pressed" << endl;
	tam3.add();

	system("pause");

	cout << "CHAR :" << endl;
	tam1.show_list();

	cout << "INT :" << endl;
	tam2.show_list();

	cout << "FLOAT :" << endl;
	tam3.show_list();

	if (tam1 != tam2) {
		cout << "Ravenstva ne ravni" << endl;
	}
	else {
		cout << "Ravenstva ravni"; 
	}

	system("pause");
	return 0;
}
