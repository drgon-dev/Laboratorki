#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;
typedef vector<float>Vec;

Vec Make_Vec(float n) {
	Vec v;
	for (int i = 0; i < n; i++) {
		int a = rand() % 100 - 50;
		v.push_back(a);
	}
	return v;
}

void Print_Vec(Vec v) {
	for (float n : v) {
		cout << n << " ";
	}
	cout << endl;
}

void Add_Mid_Beg(Vec v) {
	float mid = 0; int i = 0;
	for (float n : v) {
		mid += n;
		i++;
	}
	mid /= i;
	v.emplace(v.begin(), mid);
}

void Find_Ers(Vec v, float key) {
	int i = 0;
	for (float n : v) {
		if (n == key) {
			v.erase(v.begin() + i);
		}
		i++;
	}
}

void Min_Elem(Vec v) {
	float min = 1000;
	for (float n : v) {
		if (n < min) {
			min = n;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		v[i] -= min;
	}
}

int main() {
	Vec v;
	v = Make_Vec(1.01);
	Print_Vec(v);
	Add_Mid_Beg(v);
	Print_Vec(v);
	Find_Ers(v, v.back());
	Print_Vec(v);
	Min_Elem(v);
	Print_Vec(v);
	return 0;
}