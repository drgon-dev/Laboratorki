#pragma once
#include <list>
#include <queue>
#include <iostream>
using namespace std;

template <class T>
class List {
	queue<T> pq;
	int size;
public:
	List(void);
	List(int n);
	void Print();
	~List(void);
	void add_list(T el);
	void Add_Mid();
	void Find_Ers(T&);
	void Min_Elem();
};

template <class T>
list<T> copy_pq_to_list(queue<T> pq) {
	list<T> l;
	while (!pq.empty()) {
		l.push_back(pq.top());
		pq.pop();
	}
	return l;
}
template <class T>
queue<T> copy_list_to_pq(list<T> l) {
	queue<T> pq;
	for (auto it = l.cbegin(); it != l.cend(); ++it)
		pq.push(*it);
	return pq;
}

template <class T>
List<T>::List() {
	size = 0;
}

template <class T>
List<T>::~List() {}

template <class T>
List<T>::List(int n) {
	T a;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		pq.push(a);
	}
	size = pq.size();
}

template <class T>
void List<T>::Print() {
	list<T> l = copy_pq_to_list(pq);
	for (auto it = l.begin(); it != l.end(); ++it)
		cout << *it;
	cout << endl;
}

template <class T>
void List<T>::add_list(T el) {
	pq.push(el);
}

template<class T>
inline void List<T>::Add_Mid()
{
	List v = copy_pq_to_list(pq);
	T mid; int i = 0;
	for (auto it = v.begin(); it != v.end(); ++it) {
		mid = mid + *it;
		i++;
	}
	v.emplace(v.begin(), mid);
	pq = copy_list_to_pq(v);
}

template<class T>
inline void List<T>::Find_Ers(T&)
{
	List v = copy_pq_to_list(pq);
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (*it == key) {
			it = v.erase(it);
		}
	}
	pq = copy_list_to_pq(v);
}

template<class T>
inline void List<T>::Min_Elem()
{
	List v = copy_pq_to_list(pq);
	T min;
	min = min + 1000;
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (min < *it) {
			min = *it;
		}
	}
	for (auto it = v.begin(); it != v.end(); ++it) {
		*it = *it - min;
	}
	pq = copy_list_to_pq(v);
}
