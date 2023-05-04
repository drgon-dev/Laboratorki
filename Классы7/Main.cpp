#include "Money.h"
#include "Spisok.h"
#include <iostream>
using namespace std;
int main() {
	Money Schet(3584);
	Spisok<Money>A(Schet,10);
	cout << A;
	return 0;
}