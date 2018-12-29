#include <iostream> 
#include "math.h"
using namespace std;

int main()
{
	MathClass MC;
	int test;
	cout << "Hello World! ";

	// a = 5(00000101), b = 9(00001001) 
	unsigned char a = 5, b = 9;
	int d = 1, e = 2;
	printf("d+e= %d\n", MC.addition(d,e));

	// The result is 00001010  
	printf("a<<1 = %d\n", a << 1);

	// The result is 00010010  
	printf("b<<1 = %d\n", b << 1);
	test = cin.get();
}

int addition(int numb1, int numb2)
{
	return numb1 + numb2;
}
