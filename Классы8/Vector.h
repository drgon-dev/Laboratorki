#pragma once
#include "Object.h"
#include <iostream>
#include "Student.h"
using namespace std;
class Vector
{
protected:
	Object** dat;
	int size;
	int cur;
public:
	Vector();
	Vector(int);
	~Vector();
	void Show();
	void add();
	void del();
};