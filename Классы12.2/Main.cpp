#include "Money.h"
#include <set>

using namespace std;
typedef multiset<Money> TMS;
typedef TMS::iterator it;

TMS make_set(int n) {
	srand(time(NULL));
	TMS s;
	Money a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		s.insert(a);
	}
	return s;
}

void print_TMS(TMS m) {
	int k = 1;
	for (it i = m.begin(); i != m.end(); i++)
		cout << k++ << " : " << *i << " " << endl;
}

void Add_Mid_Beg(TMS v) {
	Money mid; int i = 0;
	for (auto it = v.begin(); it != v.end(); ++it) {
		mid = mid + *it;
		i++;
	}
	v.emplace(v.begin(), mid);
}

void Find_Ers(TMS v, Money key) {
	for (it i = v.begin(); i != v.end(); ++i) {
		if (*i == key) {
			i = v.erase(i);
		}
	}
}

void Min_Elem(TMS v) {
	Money min(1000); TMS m;
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (min < *it) {
			min = *it;
		}
	}
	for (it i = v.begin(); i != v.end(); ++i) {
		Money temp = *i - min;
		m.insert(temp);
	}
	v = m;
}


int main() {
	TMS ms; Money n;
	ms = make_set(5);
	print_TMS(ms);
	Add_Mid_Beg(ms);
	print_TMS(ms);
	cin >> n;
	Find_Ers(ms, n);
	print_TMS(ms);
	Min_Elem(ms);
	return 0;
}