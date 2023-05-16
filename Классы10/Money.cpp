#include "Money.h"
#include <fstream>

fstream& operator<<(fstream&out, Money&m)
{
	out << m.rub << "\n" << m.kop << "\n";
	return out;
}

fstream& operator>>(fstream&in, Money&m)
{
	in >> m.rub; in >> m.kop;
	return in;
}

ostream& operator<<(ostream& out, const Money& t)
{
	out << t.rub << "," << t.kop;
	return out;
}

istream& operator>>(istream& in, Money& t)
{
	cout << "rub:";
	in >> t.rub;
	cout << "kop:";
	in >> t.kop;
	return in;
}

Money::Money()
{
	rub = 0;
	kop = 0;
}

Money::Money(int a)
{
	if (a >= 100) {
		rub = a / 100;
		kop = a - (rub*100);
	}
	else
	{
		kop = a;
		rub = 0;
	}
}

Money Money::operator+(Money& b)
{
	return Money(rub * 100 + b.rub * 100 + kop + b.kop);
}

Money Money::operator ++(int)
{
	if (kop = 99) {
		rub++;
		kop = 0;
	}
	else
		kop++;
	return *this;
}

Money Money::operator++()
{
	rub++;
	return *this;
}

Money& Money::operator/(int a)
{
	rub = rub / 2;
	kop = kop / 2;
	return *this;
}

bool Money::operator>(Money&b)
{
	int temp = rub * 100 + kop;
	int temp2 = b.rub * 100 + b.kop;
	if (temp > temp2)
		return true;
	else
		return false;
}

bool Money::operator<(Money&b)
{
	int temp = rub * 100 + kop;
	int temp2 = b.rub * 100 + b.kop;
	if (temp > temp2)
		return false;
	else
		return true;
}
