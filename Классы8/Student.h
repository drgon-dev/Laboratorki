#pragma once
#include "Person.h"
class Student :
    public Person
{
protected:
    int rate;
public:
    Student() {
        name = "Petya";
        age = 1;
        rate = 0;
    }
    Student(string a,int b,int c):Person(a,b) {
        rate = c;
    }
    Student(Student& a) {
        name = a.name;
        age = a.age;
        rate = a.rate;
    }
    ~Student();
    void Show();
    void Input();
    Student& operator+(Student&);
    Student& operator-(Student&);
    friend istream& operator>>(istream&, Student&);
    friend ostream& operator<<(ostream&, const Student&);
};


