#include <iostream>
#include <set>
using namespace std;
typedef multiset<float> TMS;
typedef TMS::iterator it;

TMS make_set(int n) {
	srand(time(NULL));
	TMS s;
	float a;
	for (int i = 0; i < n; i++) {
		a = round(((float)(rand()) / RAND_MAX * 10 + 1) * 100) / 100;
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
	float mid; int i = 0;
	for (auto it = v.begin(); it != v.end(); ++it) {
		mid = mid + *it;
		i++;
	}
	v.emplace(v.begin(), mid);
}

void Find_Ers(TMS v, float key) {
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (*it == key) {
			it = v.erase(it);
		}
	}
}

void Min_Elem(TMS v) {
	float min = 1000; TMS m;
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (min < *it) {
			min = *it;
		}
	}
	for (it i = v.begin(); i != v.end(); ++i) {
		float temp = *i - min;
		m.insert(temp);
	}
	v = m;
}


int main() {
	TMS ms; float n;
	ms = make_set(5);
	print_TMS(ms);
	Add_Mid_Beg(ms);
	print_TMS(ms);
	cin >> n;
	Find_Ers(ms,n);
	print_TMS(ms);
	Min_Elem(ms);
	return 0;
}
