#include "Student.h"
Student::Student() {
	name = "Ivan";
	age = 18;
	eduage = 1;
}
Student::Student(string namei, int agei, int eduagei):Person(namei,agei)
{
	eduage = eduagei;
}
Student::Student(const Student& S) {
	name = S.name;
	age = S.age;
	eduage = S.eduage;
}
Student::~Student(void) {}
int Student::eduageo(void)
{
	return eduage;
}
void Student::ch_eduage(int eduagei) {
	eduage = eduagei;
}
void Student::outg(void) {
	cout << "--Student Information--" << endl;
	cout << "Name:" << name << endl;
	cout << "Age:" << age << endl;
	cout << "Years of education:" << eduage << endl;
}
//istream& operator<<(ostream& out, const Student& S) {
//	return(out<< "--Student Information--" << endl<<"Name:"<<S.nameo()<<endl<<"Age:"<<S.age<<)
//}
