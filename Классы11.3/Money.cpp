#include "Money.h"

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
		kop = a - (a / 100 * 100);
	}
	else
	{
		kop = a;
		rub = 0;
	}
}

Money& Money::operator+(Money& b)
{
	int temp = this->rub * 100 + this->kop + b.rub + b.kop;
	this->rub = temp / 100;
	this->kop = temp - (temp / 100);
	return *this;
}

Money& Money::operator-(Money& b)
{
	int temp = (this->rub * 100 + this->kop) - (b.rub + b.kop);
	this->rub = temp / 100;
	this->kop = temp - (temp / 100);
	return *this;
}

Money& Money::operator/(Money& b)
{
	int temp = (this->rub * 100 + this->kop) / (b.rub + b.kop);
	this->rub = temp / 100;
	this->kop = temp - (temp / 100);
	return *this;
}

bool Money::operator==(Money& b)
{
	if ((this->rub == b.rub) && (this->kop == b.kop)) {
		return true;
	}
	else
		return false;
}

bool Money::operator<(Money& b)
{
	if ((this->rub * 100 + this->kop) < (b.rub * 100 + b.kop)) {
		return true;
	}
	else
		return false;
}

bool Money::operator>(Money& b)
{
	if ((this->rub * 100 + this->kop) > (b.rub * 100 + b.kop)) {
		return true;
	}
	else
		return false;
}
