#include <iostream>

using namespace std;

const char* OP = " ";
const int cmCRF = 49;
const int cmCRS = 50;
const int cmSUM = 43;
const int cmDIF = 45;
const int cmPRO = 42;
const int cmDIV = 47;
const int cmEXIT = 48;


struct TEvent
{
	int cRegisters;
	int opCode;
	int appControl;
};

TEvent* ev = new TEvent;

class num
{
public:
	num();

	char ui(char op);
	TEvent& getEvent(char code);
	int handleEvent(TEvent& ev);
	void execute();

	void setA();
	void setB();

	void summ();
	void difference();
	void product();
	void quotient();

	double fA, fB, result;
	char cOP = ' ';
};

char num::ui(char op = *OP)
{
	cout << "================" << endl;
	cout << fA << " " << op << " " << fB << " " << "=" << " " << result << endl;
	cout << "================" << endl;

	cout << "change registers 1/2 - available operations +-*/ - 0 exit" << endl;

	char choise;
	cin >> choise;
	//if (choise == '0') return NULL;
	return choise;
}

TEvent& num::getEvent(char cd)
{
	//TEvent* ev = new TEvent;
	int tmp;
	tmp = cd;
	if (tmp == cmCRF || tmp == cmCRS)
	{
		ev->cRegisters = cd;
	}
	else if (tmp == cmEXIT)
	{
		ev->appControl = cd;
	}
	else ev->opCode = cd;
	//ev->code = cd;

	return *ev;
}

int num::handleEvent(TEvent& ev)
{

	switch (ev.cRegisters)
	{
	case cmCRF: setA(); break;
	case cmCRS: setB(); break;
	default:		break;
		//case cmEXIT:  return NULL;
	}
	ev.cRegisters = NULL;
	switch (ev.opCode)
	{
	case cmSUM: summ(); break;
	case cmDIF: difference(); break;
	case cmPRO: product(); break;
	case cmDIV: quotient(); break;
	default:		break;
	}

	switch (ev.appControl)
	{
	case cmEXIT: return 0;
	default:	break;
	}

}

void num::execute()
{
	while (handleEvent(getEvent(ui(cOP))))
	{
		system("CLS");
	}
}

void num::setA()
{
	cin >> fA;
}
void num::setB()
{
	cin >> fB;
}
void num::summ()
{
	result = fA + fB;
	cOP = '+';
}
void num::difference()
{
	result = fA - fB;
	cOP = '-';
}
void num::product()
{
	result = fA * fB;
	cOP = '*';
}
void num::quotient()
{
	result = fA / fB;
	cOP = '/';
}

num::num()
{
	fA = 0;
	fB = 0;
	result = 0;
}


int main()
{
	num n;
	n.execute();
	return 0;
}