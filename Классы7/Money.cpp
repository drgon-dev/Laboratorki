#include "Money.h"

ostream& operator<<(ostream& out, const Money& t)
{
	out << t.rub << "," << t.kop;
	return out;
}

istream& operator>>(istream& in, Money&t)
{
	cout << "rub:";
	in >> t.rub;
	cout << "kop:";
	in >> t.kop;
	return in;
}

Money Money::operator+(Money&b)
{
	return Money(rub * 100 + b.rub * 100 + kop + b.kop);
}
