#include <iostream>
using namespace std;
class Pair {
	int pairl;
	double pairr;
public:
	Pair() { pairl = 10; pairr = 100; }
	Pair(const Pair& p) {
		pairl = p.pairl;
		pairr = p.pairr;
	}
	Pair(int a, double b) {
		pairl = a;
		pairr = b;
	}
	~Pair() {}
	Pair& operator>(const Pair&);
	Pair& operator<(const Pair&);
	Pair& operator++();
	Pair& operator ++(int);
	friend istream& operator>>(istream&in, Pair&p);
	friend ostream& operator<<(ostream&out, const Pair&p);
};

