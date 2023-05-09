#pragma once
#include <iostream>
using namespace std;
class Money
{
protected:
	long rub;
	int kop;
public:
	Money() {
		rub = 0;
		kop = 0;
	}
	Money(int a){
		if (a >= 100) {
			rub = a / 100;
			kop = a - (a / 100 * 100);
		}
		else
		{
			kop = a;
			rub = 0;
		}
	}
	Money operator+(Money&);
	friend ostream& operator<<(ostream& out, const Money&);
	friend istream& operator>>(istream& in, Money&);
};

