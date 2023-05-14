#pragma once
#include "error.h"
class List
{
protected:
	int* dat;
	int size;
	int cur;
public:
	List() {
		dat = nullptr;
		size = 0;
		cur = -1;
	}
	List(int a) {
		if (a > 1000)
			throw MaxSizeErr();
		dat = new int[a];
		size = a;
		cur = size - 1;
	}
	List(List& a) {
		dat = new int[a.size];
		size = a.size;
		cur = a.cur;
		for (int i = 0; i < size; i++) {
			dat[i] = a.dat[i];
		}
	}
	List& add(int);
	List& del();
	int sh();
	int& operator[](int a);
	int& operator()();
	List& operator+(List&);
	List& operator-(int);
	friend istream& operator>>(istream&, List&);
	friend ostream& operator<<(ostream&, List&);
};
