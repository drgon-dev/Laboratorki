#pragma once
#include <iostream>
#include <string>
#include "Person.h"
class Student:
	public Person {
protected:
	int eduage;
public:
	Student(void);
	Student(string, int, int);
	Student(const Student&);
	~Student(void);
	int eduageo(void);
	void ch_eduage(int);
	void Show(void);
//	friend ostream& operator<<(ostream&, Student& S);
//	friend istream& operator>>(istream&, Student&);
};