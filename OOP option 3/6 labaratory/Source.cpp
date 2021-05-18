#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace std;

class Car
{
public:
	Car();
	Car(int, int);
	~Car();

	void print();
	int getNumber();
	int getNumber2();
	void setNumber(int N);
	void setNumber2(int S);

	bool operator<(const Car&);
	bool operator==(const Car&);
private:
	int number;
	int name;
};


Car::Car()
{
	number = 0;
	name = 0;
}
Car::Car(int N, int S)
{
	number = N;
	name = S;
}

Car::~Car()
{

}

void Car::print()
{
	cout << name << "========" << number;
}
int Car::getNumber()
{
	return number;
}
int Car::getNumber2()
{
	return name;
}
void Car::setNumber(int N)
{
	number = N;
}
void Car::setNumber2(int S)
{
	name = S;
}

bool Car::operator<(const Car& d)
{
	return this->number < d.number;
}

bool Car::operator==(const Car& d)
{
	return this->number == d.number && this->name == d.name;
}


void OneQuestion();
void TwoQuestion();
void ThreeQuestion();




int main()
{
	cout << "-_- 1 Question -_-" << endl;
	cout << endl;
	OneQuestion();
	cout << endl;
	cout << endl;
	cout << "-_- 2 Question -_-" << endl;
	cout << endl;
	TwoQuestion();
	cout << endl;
	cout << endl;
	cout << "-_- 3 Question -_-" << endl;
	cout << endl;
	ThreeQuestion();
	return 0;
}

void OneQuestion()
{
	deque<int> count;
	deque<int> ::iterator it;

	for (int i = 0; i < 10; i++)
	{
		if (i < 3)
		{
			count.push_back(111);
			continue;
		}
		if (i < 6)
		{
			count.push_back(222);
			continue;
		}
		if (i < 9)
		{
			count.push_back(333);
			continue;
		}
		count.push_back(444);
	}

	for (int i = 0; i < count.size(); i++)
	{
		cout << count[i] << " ";
	}

	cout << endl;

	replace(count.begin(), count.end(), 111, 222);
	for (int i = 0; i < count.size(); i++)
	{
		if (count[i] == 333)
		{
			count.erase(count.begin() + i);
			i--;
		}
		if (count[i] == 444)
		{
			count.erase(count.begin() + i);
			i--;
		}
	}

	it = count.begin();

	while (it != count.end())
	{
		cout << *it << " ";
		it++;
		
	}

}	

void TwoQuestion()
{
	deque<Car> count;
	deque<Car> ::iterator it;

	for (int i = 0; i < 10; i++)
	{

		if (i < 5)
		{
			Car d;
			count.push_back(d);
			continue;
		}
		Car c(500, 101);
		count.push_back(c);
	}

	for (int i = 0; i < count.size(); i++)
	{
		count[i].print();
		cout << endl;
	}
	cout << endl;
	cout << "OMG 4TO ETO TAKOE" << endl;

	//replace(count.begin(), count.end(), "abc", "xyz");
	for (int i = 0; i < count.size(); i++)
	{
		if (count[i].getNumber() == 0)
		{
			count.erase(count.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < count.size(); i++)
	{
		if (count[i].getNumber() == 500)
		{
			count[i].setNumber2(96);
			count[i].setNumber(69);
		}
	}

	it = count.begin();

	while (it != count.end())
	{
		(*it).print();
		it++;
		cout << endl;
	}

}

void ThreeQuestion()
{
	deque<Car> count;
	for (int i = 0; i < 3; i++)
	{
		Car d(i * 100, 1);
		count.push_back(d);
	}
	for (int i = 0; i < 5; i++)
	{
		Car d(i * 50, 2);
		count.push_back(d);
	}
	for (int i = 0; i < 4; i++)
	{
		Car d(i * 1000, 3);
		count.push_back(d);
	}
	for (int i = 0; i < count.size(); i++)
	{
		count[i].print();
		cout << endl;
	}
	cout << "------------------------" << endl;
	sort(count.rbegin(), count.rend());
	for (int i = 0; i < count.size(); i++)
	{
		count[i].print();
		cout << endl;
	}
	cout << "------------------------" << endl;
	deque<Car> ncount;
	for (int i = 0; i < count.size(); i++)
	{
		if (count[i].getNumber() < 500)
		{
			ncount.push_back(count[i]);
			count.erase(count.begin() + i);
			i--;
		}
	}
	sort(count.begin(), count.end());
	for (int i = 0; i < count.size(); i++)
	{
		count[i].print();
		cout << endl;
	}
	cout << "-----------------------" << endl;
	sort(ncount.begin(), ncount.end());
	for (int i = 0; i < ncount.size(); i++)
	{
		ncount[i].print();
		cout << endl;
	}

}