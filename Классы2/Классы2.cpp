#include <iostream>
#include "Header.h"
using namespace std;
int main() {
	int a = 10; string b = "01.01.2000"; double c = 3582785;
	kvit num1;
	num1.chnum(a);
	num1.chdata(b);
	num1.chsum(c);
	cout << num1.numberc();
	cout << num1.datac();
	cout << num1.sumc();
	kvit num2(num1);
	cout << num2.numberc();
	cout << num2.datac();
	cout << num2.sumc();
	kvit num3(a, b, c);
	cout << num3.numberc();
	cout << num3.datac();
	cout << num3.sumc();
	return 0;
}