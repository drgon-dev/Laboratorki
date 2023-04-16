#pragma once
#include "Object.h"
#include <iostream>
#include <string>
using namespace std;
class Vector {
private:
	Object** beg;
	int size;
	int cur;
public:
	Vector(void);
	Vector(int);
	~Vector(void);
	void Add(Object*);
	friend ostream& operator<<(ostream& out, const Vector&);
};