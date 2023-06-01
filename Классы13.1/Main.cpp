#include <iostream>
#include <list>
#include <queue>
#include <numeric>
#include <algorithm>
#include <map>
#include "Pair.h"

using namespace std;

void ex_1()
{
	cout << "Введите размер листа: " << endl;
	int n;
	cin >> n;
	list<Pair> lst;
	Pair p;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		lst.push_back(p);
	}
	Pair sr = accumulate(lst.begin(), lst.end(), Pair(0, 0));
	sr.a = sr.a / lst.size();
	sr.b = sr.b / lst.size();
	lst.push_back(sr);
	cout << "Среднее:\n";
	for_each(lst.begin(), lst.end(), [](Pair p) {cout << p << endl; });
	cout << "Введите удаляемое: " << endl;
	cin >> p;
	auto it = remove(lst.begin(), lst.end(), p);
	lst.erase(it, lst.end());
	cout << "Удаление заданного: " << endl;
	for_each(lst.begin(), lst.end(), [](Pair p) {cout << p << endl; });
	cout << "Добавление макс и мин: " << endl;
	Pair max = *max_element(lst.begin(), lst.end());
	Pair min = *min_element(lst.begin(), lst.end());
	for (Pair& c : lst)
	{
		c = c + max + min;
		cout << c << endl;
	}
}
bool operator<(const Pair& pr1, const Pair& pr2)
{
	return ((pr1.a < pr2.a) && (pr1.b < pr2.b));
}

int main(){
	ex_1();
	return 0;
}