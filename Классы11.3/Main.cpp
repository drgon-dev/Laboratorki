#include "Money.h"
#include "List.h"
#include <iostream>
#include <list>
#include <cstdlib>

int main() {
	List<Money> l(3); Money Mn;
	for (int i = 0; i < 3; i++) {
		cin >> Mn;
		l.add_list(Mn);
	}
	l.Print();
	l.Add_Mid();
	l.Print();
	cin >> Mn;
	l.Find_Ers(Mn);
	l.Print();
	l.Min_Elem();
	l.Print();
	return 0;
}
