#include <iostream>
#include <string>
#include "Object.h"
using namespace std;
class Person:
	public Object
{
protected:
	string name;
	int age;
public:
	Person(void);
	Person(string, int);
	Person(const Person&);
	~Person(void);
	void Show();
	int ageo(void);
	string nameo(void);
};