#include <iostream>
#include "Header.h"
using namespace std;
int main() {
	int a;
	Pair kek, kekus;
	cin >> kek >> kekus >> a;
	if (a == 1) 
		kek > kekus;
	else 
		kek < kekus;
	cout << kek << " " << kekus << endl;
	kek++;
	cout << kek << endl;
	++kek;
	cout << kek << " " <<kekus;
	return 0;
}