#include "BigInteger.h"
#include <conio.h>

int divide(int, int);
int main()
{
	BigInteger integer1, integer2;
	cin >> integer1 >> integer2;
	cout << integer1 + integer2;
	getchar(); 
	return 0;
}