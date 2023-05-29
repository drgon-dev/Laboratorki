#pragma once
#include <list>
#include <iostream>

using namespace std;

template <class T>
class List {
	list <T> v;
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
		v.push_back(a);
	}
	size = v.size();
}

template <class T>
void List<T>::Print() {
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it;
	cout << endl;
}

template <class T>
void List<T>::add_list(T el) {
	v.insert(v.end(), el);
}

template<class T>
inline void List<T>::Add_Mid()
{
	T mid; int i = 0;
	for (auto it = v.begin(); it != v.end(); ++it) {
		mid = mid + *it;
		i++;
	}
	v.emplace(v.begin(), mid);
}

template<class T>
inline void List<T>::Find_Ers(T&)
{
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (*it == key) {
			it = v.erase(it);
		}
	}
}

template<class T>
inline void List<T>::Min_Elem()
{
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
}
