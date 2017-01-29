#include "BigInteger.h"
#include <fstream>
#include <conio.h>
using namespace std;


int main()
{
	ofstream offill;
	BigInteger integer1, integer4;
	BigInteger integer5 = "1";
	BigInteger integer2 = "1000000";
	BigInteger integer3 = "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
	for (integer1 = "0", integer4 = "0"; integer4 < integer2 ; integer4 = integer4 + integer5, integer1 = integer1 + integer3)
	{
		cout << integer1 << endl;
	}
	offill.open("result.txt", ios::out);
	string output = integer1.ToString();
	offill << output;
	offill.close();
	return 0;
}