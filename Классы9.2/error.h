#pragma once
#include<string>
#include<iostream>
using namespace std;
class error {
protected:
	string str;
public:
	error(string s) { str = s; }
	void what() { cout << str << endl; }
};