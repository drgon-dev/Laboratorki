#include "Spisok.h"
#include <iostream>

Spisok::Spisok(void)
{
	data = new int[5];
	size = 5;
	cur = 0;
}

Spisok::Spisok(int ssize)
{
	data = new int[ssize];
	size = ssize;
	cur = 0;
}

Spisok::Spisok(int ssize, int ccur)
{
	data = new int[ssize];
	size = ssize;
	cur = ccur;
}

Spisok::~Spisok(void)
{
	delete data;
}

int& Spisok::operator[](int index)
{
	if (index <= size)
		return data[index];
	else
	{
		cout << "ERROR";
		return data[0];
	}
}

Spisok Spisok::operator ++(int)
{
	Spisok temp(size,cur);
	for (int i = 0; i < size; i++) {
		temp.data[i] = data[i];
	}
	if (temp.cur == (size - 1))
		temp.cur = 0;
	else temp.cur++;
	return temp;
}

Spisok& Spisok::operator+(const int ch)
{
	Spisok temp(size);
	for (int i = 0; i < size; i++) {
		temp.data[i] = data[i]+ch;
	}
	return temp;
}

istream& operator>>(istream& in, Spisok& S)
{
	for (int i = 0; i < S.size; i++) {
		in >> S.data[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const Spisok&S)
{
	for (int i = 0; i < S.size; i++) {
		cout << S.data[i]<<endl;
	}
	return out;
}