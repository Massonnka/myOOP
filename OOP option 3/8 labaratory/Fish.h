#pragma once
#include "Pet.h"
#include <cstring>
#include <iostream>

using namespace std;

class Fish :public Pet
{
private:
	char* name;
public:
	char* getName() const override {
		return this->name;
	}
	void setName(const char* name) override {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	void play() override {
		cout << name << " просто чел плавает" << endl;
	}
	~Fish() {
		if (name) delete[] name;
	}
};

