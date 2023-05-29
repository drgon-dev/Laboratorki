#include "Money.h"
#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;
typedef list<Money>List;
//Создание контейнера
List Make_Vec(int n) {
	List v;
	for (int i = 0; i < n; i++) {
		Money ab;
		cin >> ab;
		v.push_back(ab);
	}
	return v;
}
//Вывод контейнера
void Print_Vec(List v) {
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}
//Найти среднее арифметическое и добавить в начало
void Add_Mid_Beg(List v) {
	Money mid; int i = 0;
	for (auto it = v.begin(); it != v.end(); ++it) {
		mid = mid + *it;
		i++;
	}
	v.emplace(v.begin(), mid);
}
//Найти элемент по ключу и удалить
void Find_Ers(List v, Money key) {
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (*it == key) {
			it = v.erase(it);
		}
	}
}
//Вычесть минимальный из каждого элемента
void Min_Elem(List v) {
	Money min(1000);
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (min < *it) {
			min = *it;
		}
	}
	for (auto it = v.begin(); it != v.end(); ++it) {
		*it = *it - min;
	}
}

int main(){
	List v;
	v = Make_Vec(5);
	Print_Vec(v);
	Add_Mid_Beg(v);
	Print_Vec(v);
	Find_Ers(v, v.back());
	Print_Vec(v);
	Min_Elem(v);
	Print_Vec(v);
	return 0;
}