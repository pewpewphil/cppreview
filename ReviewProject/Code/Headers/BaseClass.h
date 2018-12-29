#pragma once
class Base
{
public:
	Base();

	int ReturnIncrease(int number);

	 ~Base();
};

class Derived1 : public Base
{
public:
	Derived1();
	~Derived1();
};