#include "List.h"
#include "List.h"

List& List::add(int a)
{
	if ((size + 1) > 1000)
		throw error(">maxsize");
	List An(size+1);
	for (int i = 0; i < size; i++) {
		An.dat[i] = dat[i];
	}
	An.dat[size] = a;
	return An;
}

List& List::del()
{
	if (size == 0)
		throw error("List is empty");
	List An(size - 1);
	for (int i = 0; i < size-1; i++) {
		An.dat[i] = dat[i];
	}
	return An;
}

int List::sh()
{
	return dat[size - 1];
}

int& List::operator[](int a)
{
	if (a >= size)
		throw error("incorrect index");
	return dat[a];
}

int& List::operator()()
{
	return cur;
}

List& List::operator+(List&b)
{
	if (size != b.size)
		throw error("list sizes are not equal");
	List An(size);
	for (int i = 0; i < size; i++) {
		An.dat[i] = dat[i] + b.dat[i];
	}
	return An;
}

List& List::operator-(int n)
{
	if ((cur - n) < 0)
		throw error("incorrect n");
	cur -= n;
	return *this;
}

istream& operator>>(istream&in, List&a)
{
	for (int i = 0; i < a.size; i++) {
		cout << "input:"; in >> a.dat[i];
	}
	return in;
}

ostream& operator<<(ostream&out, List&a)
{
	for (int i = 0; i < a.size; i++) {
		out << "1:" << a.dat[i] << endl;
	}
	return out;
}
