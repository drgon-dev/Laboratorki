#include "Vector.h"

Vector::Vector()
{
	dat = nullptr;
	size = 0;
	cur = 0;
}

Vector::Vector(int a)
{
	dat = new Object*[a];
	size = a;
	cur = 0;
}

Vector::~Vector()
{
	delete dat;
}

void Vector::Show()
{
	if (cur == 0)
		cout << "EMPTY";
	Object** a = dat;
	for (int i = 0; i < cur; i++) {
		(*a)->Show();
		a++;
	}
}

void Vector::add()
{
	Object* Ob = new (Student);
	Ob->Input();
	if ((cur + 1) <= size) {
		dat[cur] = Ob;
		cur++;
	}
	else
		cout << "ERROR:OVERFLOW";
}

void Vector::del()
{
	cur--;
}


