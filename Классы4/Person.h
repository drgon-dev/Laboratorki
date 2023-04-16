#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
	string name;
	int age;
public:
	Person(void);
	Person(string, int);
	Person(const Person&);
	~Person(void);
	int ageo(void);
	string nameo(void);
};