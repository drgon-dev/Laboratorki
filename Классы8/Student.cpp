#include "Student.h"

Student::~Student(){}

void Student::Show()
{
	cout << "NAME IS " << name << endl;
	cout << "AGE IS " << age << endl;
	cout << "RATING IS " << rate << endl;
}

void Student::Input()
{
	cout << "NAME:"; cin >> name; 
	cout << "AGE:"; cin >> age;
	cout << "RATING:"; cin >> rate;
}

Student& Student::operator+(Student& b)
{
	Student An;
	An.rate = rate + b.rate;
	return An;
}

Student& Student::operator-(Student&b)
{
	Student An;
	An.rate = rate + b.rate;
	return An;
}

istream& operator>>(istream&in, Student&a)
{
	cout << "RATING:"; in >> a.rate;
	return in;
}

ostream& operator<<(ostream&out, const Student&a)
{
	out << "RATING IS EQUAL TO " << a.rate;
	return out;
}
