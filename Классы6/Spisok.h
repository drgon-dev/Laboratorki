#pragma once
#include <string>
#include <iostream>
using namespace std;
class Spisok {
private:
	int *data;
	int size;
	int cur;
public:
	Spisok(void);
	Spisok(int);
	Spisok(int, int);
	~Spisok(void);
	int& operator[](int index);
	int& operator()() {
		return size;
	}
	Spisok operator ++(int);
	Spisok& operator+(int);
	friend istream& operator>>(istream& in, Spisok& S);
	friend ostream& operator<<(ostream& out, const Spisok&);
};