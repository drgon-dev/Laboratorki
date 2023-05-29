#include <iostream>
#include <set>
#include "List.h"
#include "Money.h"


using namespace std;

int main() {
	Money m;
	List<Money> l(3);
	l.Print();
	l.Add_Mid();
	l.Print();
	cin >> m;
	l.Find_Ers(m);
	l.Print();
	l.Min_Elem();
	l.Print();
	return 0;
}