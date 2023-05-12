#pragma once
#include <string>
#include <iostream>
#include "Object.h"
using namespace std;
class Person :
    public Object
{
protected:
    string name;
    int age;
public:
    Person() {
        name = "Ivan";
        age = 0;
    }
    Person(string a, int b) {
        name = a;
        age = b;
    }
    Person(Person& a) {
        name = a.name;
        age = a.age;
    }
    ~Person();
    void Show();
    friend istream& operator<< (istream & in, Person & a) {
        cout << "NAME:"; in >> a.name;
        cout << "AGE:"; in >> a.age;
        return in;
    }
    friend ostream& operator>>(ostream& out, Person& a) {
        out << "NAME IS" << a.age << endl;
        out << "AGE IS" << a.age;
        return out;
    }
};

