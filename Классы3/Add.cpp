#include <iostream>
#include "Header.h"
using namespace std;
istream&operator>>(istream&in, Pair&p) {
	cout << "left "; in >> p.pairl;
	cout << "right "; in >> p.pairr;
	return in;
}
ostream& operator<<(ostream& out, const Pair&p) {
	return (out << p.pairl << " : " << p.pairr);
}
Pair& Pair::operator>(const Pair& p) {
	if ((pairr > p.pairr) && (pairl > p.pairl)) return *this;
	else
	{
		pairr = p.pairr;
		pairl = p.pairl;
		return *this;
	}
}
Pair& Pair::operator<(const Pair&p) {
	if ((pairr < p.pairr) && (pairl < p.pairl)) return *this;
	else
	{
		pairr = p.pairr;
		pairl = p.pairl;
		return *this;
	}
}
Pair& Pair::operator++() {
	pairl++;
	return *this;
}
Pair&Pair::operator ++(int) {
	pairr++;
	return *this;
}