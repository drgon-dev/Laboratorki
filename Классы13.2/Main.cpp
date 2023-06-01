#include <iostream>
#include <list>
#include <queue>
#include <numeric>
#include <algorithm>
#include <map>
#include "Pair.h"

using namespace std;

void ex_2()
{
	priority_queue <Pair> lst;
	priority_queue <Pair> tmp;
	lst.push(Pair(1, 1.5));
	lst.push(Pair(-2, 2.7));
	lst.push(Pair(3, -3.2));
	cout << "Изначальный список:\n";
	Pair sr(0, 0);
	while (!lst.empty())
	{
		cout << lst.top() << endl;
		sr = sr + lst.top();
		tmp.push(lst.top());
		lst.pop();
	}
	sr.a /= tmp.size();
	sr.b /= tmp.size();
	cout << "Среднее ариф., добавленное в конец:\n";
	while (!tmp.empty())
	{
		cout << tmp.top() << endl;
		lst.push(tmp.top());
		tmp.pop();
	}
	lst.push(sr);
	cout << sr << endl;
	int k = 1;
	int i, j;
	Pair res;
	cout << "Диапозон: "; cin >> i >> j;
	cout << "Ключ: ";  cin >> res;
	while (!lst.empty())
	{
		if ((k < i) || (k > j) || (res != lst.top()))
		{
			tmp.push(lst.top());
		}
		lst.pop();
		k++;
	}
	cout << "Удаленные элементы из заданного диапозона:\n";
	Pair max = tmp.top();
	Pair min = tmp.top();
	while (!tmp.empty())
	{
		if (max < tmp.top()) max = tmp.top();
		if (tmp.top() < min) min = tmp.top();
		cout << tmp.top() << endl;
		lst.push(tmp.top());
		tmp.pop();
	}
	cout << "Добавить макс. и мин. к каждому элементу:\n";
	while (!lst.empty())
	{
		tmp.push(max + min + lst.top());
		lst.pop();
	}
	while (!tmp.empty())
	{
		lst.push(tmp.top());
		cout << tmp.top() << endl;
		tmp.pop();
	}
}

int main(){
	ex_2();
	return 0;
}