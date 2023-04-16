#include <iostream>
#include "Header.h"
using namespace std;

talk make(int first,float second) {
	talk t1;
	t1.init(first, second);
	return t1;
}

int main() {
	int a; float b;
	cin >> a >> b;
	talk done;
	done.init(a, b);
	done.show();
	done.cost();
	talk ttt = make(124, 0.5424);
	ttt.show();
	return 0;
}