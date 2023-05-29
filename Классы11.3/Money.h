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
	Money& operator+(Money&);
	Money& operator-(Money&);
	Money& operator/(Money&);
	bool operator==(Money&);
	bool operator<(Money&);
	bool operator>(Money&);
	friend ostream& operator<<(ostream&, const Money&);
	friend istream& operator>>(istream&, Money&);
};