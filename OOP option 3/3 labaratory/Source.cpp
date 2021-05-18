#include <stdio.h>
///#include <stdafx.h>
#include <conio.h>
#include <iostream>
///#include <vector>
 
using namespace std;

class SetChar {
private:
	char* setChar;
	const unsigned int maxSize = maxSize;
	int size;

	int find(char sym) {
		for (int i = 0; i < size; i++) {
			if (this->setChar[i] == sym) {
				return i;
			}
		}

		return -1;
	}


public:
	SetChar() {
		setChar = NULL;
		this->size = 0;

		cout << "Kontstryktor" << endl;
	}

	SetChar(char* charArray, unsigned int size) {

	}

	SetChar(const SetChar& ob) {
		size = ob.size;
		setChar = new char[ob.size];
		for (int index = 0; index < size; index++)
			setChar[index] = ob.setChar[index];
	}

	~SetChar() {
		if (setChar != NULL) {
			delete[] setChar;
		}
		cout << " Destructor" << endl;
	}



	SetChar& operator-(char del) {
		for (int index1 = 0; index1 < size; index1++)
			if (setChar[index1] == del)
				for (int index2 = index1; index2 < size + 1; index2++)
					setChar[index2] = setChar[index2 + 1];
		return *this;
	}

	SetChar& operator = (const SetChar& ob) { //присваивание
		if (size > ob.size) {
			for (int index = 0; index < ob.size; index++)
				setChar[index] = ob.setChar[index];
			for (int index = ob.size; index < size; index++)
				setChar[index] = 0;
		}
		else {
			for (int index = ob.size; index < size; index++)
				setChar[index] = ob.setChar[index];
		}

		return *this;
	}

	friend SetChar& operator>(SetChar ob, SetChar ob1) {
		
	}

	bool operator!=(SetChar ob) {
		for (int i = 0; i < this->size; i++) {
			if (ob.find(this->setChar[i]) == -1) {
				return false;
			}
		}

		return true;
	}

	friend ostream& operator<<(ostream& output, const SetChar& r) {
		if (r.charSet != NULL) {
			for (int i = 0; i < r.currentSize; i++) {
				output << r.charSet[i] << ' ';
			}
		}
		else {
			output << "empty";
		}
		return output;
	}

};

int main(void) {
	char xVector[] = { '1', '2', '3', '1' };
	char yVector[] = { '4', '2' };

	SetChar xSetChar(xVector, 4), ySetChar;

	cout << "x SetChar: " << xSetChar << endl;
	cout << "y SetChar: " << ySetChar << endl;

	for (int i = 0; i < 2; i++) {
		ySetChar = ySetChar - yVector[i];
	}

	xSetChar = xSetChar;
	xSetChar = xSetChar;
	xSetChar = xSetChar;

	cout << "x SetChar: " << xSetChar << endl;
	cout << "y SetChar: " << ySetChar << endl;

	SetChar zSetChar;

	zSetChar = xSetChar - '1';
	zSetChar = zSetChar - 'a';
	zSetChar = zSetChar - 'x';

	zSetChar = zSetChar - xSetChar;
	zSetChar = zSetChar - ySetChar;
	zSetChar = zSetChar - zSetChar;

	cout << "z SetChar: " << zSetChar << endl;

	if (xSetChar != xSetChar) {
		cout << "xSetChar equels xSetChar" << endl;
	}
	else {
		cout << "Error in == operator" << endl;
	}

	if (!(ySetChar != zSetChar)) {
		cout << "ySetChar not equels zSetChar" << endl;
	}
	else {
		cout << "Error in == operator" << endl;
	}

	return 0;
}