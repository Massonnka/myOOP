#include <iostream> 
#include "math.h"
#include <string>
#include <typeinfo>
#include <new>
#include <fstream>
#include <bitset>

using namespace std;

class error
{
public:
	error(int code)
		: m_code(code)
	{}

	int m_code;
};

int main()
{
	int a = -1;
	int* p = 0;
	string str = "Example";
	ifstream file;
	file.open("emp.txt", ios::in);

	try
	{
		throw a;
	}
	catch (int a)
	{
		std::cerr << "We caught an int exception with value " << a << '\n';
	}
	try
	{
		throw str;
	}
	catch (const std::string & str)
	{
		std::cerr << "We caught an exception of type std::string " << str << '\n';
	}
	try
	{
		bitset< 33 > bitset;
		bitset[32] = 1;
		bitset[0] = 1;
		unsigned long x = bitset.to_ulong();
	}
	catch ( exception &e )
	{
		cerr << "Caught " << e.what() << endl;
		cerr << "Type " << typeid(e).name() << endl;
	}
	try
	{
		if (!file) {
			throw "File not found";
		}
	}
	catch (const char* e)
	{
		cerr << "We have Error: " << e << endl;
	}
	try
	{
		int* myarray = new int[10000];
	}
	catch (std::bad_alloc & ba)
	{
		std::cerr << ba.what() << std::endl;
	}
	try
	{
		throw error(115);
	}
	catch (const error & e)
	{
		cerr << "We have custom error " << e.m_code << endl;
	}
}