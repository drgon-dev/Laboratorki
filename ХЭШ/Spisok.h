#pragma once
#include <string>
using namespace std;
class Spisok {
protected:
	string* data;
	int size;
public:
	Spisok(){
		data = new string[1];
		size = 1;
	}
	Spisok(int ssize) {
		data = new string[ssize];
		size = ssize;
	}
	Spisok(Spisok& S) {
		size = S.size;
		data = new string[size];
		for (int i = 0; i < S.size; i++) {
			data[i] = S.data[i];
		}
	}
	Spisok& add(string added) {
		Spisok temp(size+1);
		for (int i = 0; i < size; i++) {
			temp.data[i] = data[i];
		}
		temp.data[size] = added;
	}
};
