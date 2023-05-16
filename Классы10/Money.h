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
	Money operator+(Money&);
	Money operator ++(int);
	Money operator++();
	Money& operator/(int);
	bool operator>(Money&);
	bool operator<(Money&);
	friend fstream& operator<<(fstream&, Money&);
	friend fstream& operator>>(fstream&, Money&);
	friend ostream& operator<<(ostream& out, const Money&);
	friend istream& operator>>(istream& in, Money&);
};