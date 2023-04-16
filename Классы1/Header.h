#include <iostream>
using namespace std;
class talk {
private:
	int first;
	float second;
public:
	void init(int time, float cost) {
		first = time;
		second = cost;
	}
	void show() {
		cout << first << endl << second << endl;
	}
	void cost() {
		cout << first * second << endl;
	}
	void read() {
		cin >> first;
		cin >> second;
	}
};
