#include "Money.h"
#include "Spisok.h"
#include <iostream>
using namespace std;
int main() {
	Money Schet(3584);
	Spisok<Money>A(Schet,2);
	Spisok<Money>B(Schet, 2);
	cin >> A;
	cout << A;
	cout << A + B;
	return 0;
}