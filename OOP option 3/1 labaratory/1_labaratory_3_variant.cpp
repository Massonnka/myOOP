#include <iostream>
#include "Library.h"

int main()
{
	// создание 
	Library* library = new Library();

	// инициализация переменных
	char name[25] = "Adress name";
	char street[25] = "Street name ";
	int coust = 1.1;
	library->set(name, street, coust);

	// использование функции указателя
	void (Library:: * ptLibrary) () = &Library::show;
	(*library.*ptLibrary)();

	// удаление
	delete library;
}
