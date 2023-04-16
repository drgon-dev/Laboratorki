#include "Person.h"
#include <iostream>
#include <string>
using namespace std;
Person::Person(void) {
	name = "Ivan";
	age = 1;
}
Person::Person(string namei, int agei)
{
	name = namei;
	age = agei;
}

Person::Person(const Person&P)
{
	name = P.name;
	age = P.age;
}

Person::~Person(void){}

int Person::ageo(void)
{
	return age;
}

string Person::nameo(void)
{
	return name;
}
void Person::Show(void) {
	cout << name << endl;
	cout << age << endl;
}
