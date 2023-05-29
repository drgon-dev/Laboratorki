#pragma once
#include <iostream>
using namespace std;
class Money
{
protected:
	long rub;
	int kop;
public:
	Money();
	Money(int);
	Money& operator+(const Money&);
	Money& operator-(const Money&)const;
	Money& operator/(Money&);
	bool operator==(const Money&)const;
	bool operator<(const Money&);
	bool operator>(const Money&);
	friend ostream& operator<<(ostream&, const Money&);
	friend istream& operator>>(istream&, Money&);
};