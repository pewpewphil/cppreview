#include <iostream>
#include "Headers/BaseClass.h"
using namespace std;

Base::Base()
{
	cout << "Base Constructor Called\n";
}

int Base::ReturnIncrease(int number)
{
	return number + 1;
}

Base::~Base() {
	cout << "Base Destructor called\n";
}


Derived1::Derived1()
{
	cout << "Derived constructor called\n";
}

Derived1::~Derived1()
{
	cout << "Derived destructor called\n";
}
