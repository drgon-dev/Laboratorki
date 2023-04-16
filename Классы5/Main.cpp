#include <iostream>
#include "Student.h"
#include "Object.h"
#include "Vector.h"
using namespace std;
int main() {
	Vector v(5);
	Student Cmo("Petr", 20, 2);
	Student Chmoha("Ivan",20,2);
	Chmoha.Show();
	Object* p = &Cmo;
	v.Add(p);
	p = &Chmoha;
	v.Add(p);
	cout << v;
	return 0;
}