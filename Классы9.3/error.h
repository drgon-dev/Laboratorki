#pragma once
#include<string>
#include<iostream>
using namespace std;
class error {
public:
	virtual void what() {};
};
class IndexErr :public error {
protected:
	string msg;
public:
	IndexErr() { msg = "IndexError\n"; }
	virtual void what() { cout << msg; }
};
class SizeErr :public error {
protected:
	string msg;
public:
	SizeErr() { msg = "Size Error\n"; }
	virtual void what() { cout << msg; }
};
class MaxSizeErr :public SizeErr {
protected:
	string msg_;
public:
	MaxSizeErr() { msg_ = "Size>Maxsize\n"; }
	virtual void what() { cout << msg << msg_ << endl; }
};
class EmptErr :public error {
protected:
	string msg;
public:
	EmptErr() { msg = "List is empty Error\n"; }
	virtual void what() { cout << msg; }
};
class NtEqErr :public SizeErr {
protected:
	string msg_;
public:
	NtEqErr() { msg = "List sizes are not equal\n"; }
	virtual void what() { cout << msg << msg_ << endl; }
};
class IncErr :public error {
protected:
	string msg;
public:
	IncErr() { msg = "N not correct\n"; }
	virtual void what() { cout << msg; }
};