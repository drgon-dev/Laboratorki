#include <iostream>
#include <queue>
#include <list>
#include "Money.h"

using namespace std;
typedef queue<Money> Que;
typedef list<Money> List;

Que& New_Que(int n) {
	Que temp; Money expl;
	for (int i = 0; i < n; i++) {
		cin >> expl;
		temp.push(expl);
	}
	return temp;
}

List QueList(Que& Q) {
	List l;
	while (!Q.empty()) {
		l.push_back(Q.front());
		Q.pop();
	}
	return l;
}

void PrintQue(Que& Q) {
	List v;
	v = QueList(Q);
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

Que ListQue(List& L) {
	Que Q;
	for (auto it = L.cbegin(); it != L.cend(); ++it)
		Q.push(*it);
	return Q;
}
//Найти среднее арифметическое и добавить в начало
void Add_Mid(Que& Q) {
	List v = QueList(Q);
	Money mid; int i = 0;
	for (auto it = v.begin(); it != v.end(); ++it) {
		mid = mid + *it;
		i++;
	}
	v.emplace(v.begin(), mid);
	Q = ListQue(v);
}
//Найти элемент по ключу и удалить
void Find_Ers(Que& Q, Money& key) {
	List v = QueList(Q);
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (*it == key) {
			it = v.erase(it);
		}
	}
	Q = ListQue(v);
}
//Вычесть минимальный из каждого элемента
void Min_Elem(Que& Q) {
	List v = QueList(Q);
	Money min(1000);
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (min < *it) {
			min = *it;
		}
	}
	for (auto it = v.begin(); it != v.end(); ++it) {
		*it = *it - min;
	}
	Q = ListQue(v);
}

int main() {
	Que Q; Money Mn;
	Q = New_Que(5);
	PrintQue(Q);
	Add_Mid(Q);
	PrintQue(Q);
	cin >> Mn;
	Find_Ers(Q,Mn);
	PrintQue(Q);
	Min_Elem(Q);
	PrintQue(Q);
	return 0;
}