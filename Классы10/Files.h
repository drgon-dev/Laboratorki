#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Money.h"
using namespace std;
int makefile(const char* fname) {
	fstream stream(fname, ios::out | ios::trunc);
	if (!stream)
		return-1;
	int n;
	Money m;
	cout << "How many:"; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		stream << m<<"\n";
	}
	stream.close();
	return n;
}
int printfile(const char* fname) {
	Money m; int i = 0;
	fstream stream(fname, ios::in);
	if (!stream)
		return -1;
	while(stream >> m) {
		cout << m<<"\n";
		i++;
	}
	stream.close();
	return i;
}
int delelem(const char* fname, int a) {
	Money m; int i = 0;
	fstream temp("temp", ios::out);
	fstream stream(fname, ios::in);
	while (stream >> m) {
		if (stream.eof())
			break;
		if (i != a)
			temp<<m;
		i++;
	}
	stream.close();
	temp.close();
	remove(fname);
	rename("temp", fname);
	return i;
}
int adelem(const char* fname, int a) {
	Money m, mm; int i = 0,l=0;
	fstream temp("temp", ios::out);
	fstream stream(fname, ios::in);
	while (stream >> m) {
		if(stream.eof())
			break;
		if (i == a) {
			cin >> mm;
			temp << mm;
			l++;
		}
		temp << m;
		i++;
	}
	stream.close();
	temp.close();
	remove(fname);
	rename("temp", fname);
	return l;
}
int chelem(const char* fname, int a) {
	Money m, mm; int i = 0, l = 0;
	fstream temp("temp", ios::out);
	fstream stream(fname, ios::in);
	while (stream >> m) {
		if (stream.eof())
			break;
		if (i == a) {
			cin >> mm;
			temp << mm;
			l++;
		}
		else
			temp << m;
		i++;
	}
	stream.close();
	temp.close();
	remove(fname);
	rename("temp", fname);
	return l;
}
int deles(const char* fname) {
	Money m, mm; int l = 0;
	fstream stream(fname, ios::in);
	fstream temp("temp", ios::out);
	cin >> mm;
	while (stream >> m) {
		if (stream.eof())
			break;
		if (m > mm) {
			temp << m;
		}
		else
			l++;
	}
	stream.close();
	temp.close();
	remove(fname);
	rename("temp", fname);
	return l;
}
int adelems(const char* fname, int a) {
	Money m, mm; int i = 0, l = 0, b = 0;
	fstream stream(fname, ios::in);
	fstream temp("temp", ios::out);
	cout << "How many elements:"; cin >> b;
	while (stream >> m) {
		if (stream.eof())
			break;
		temp << m;
		if (i == a) {
			for (int j = 0; j < b; j++) {
				cin >> mm;
				temp << mm;
				l++;
			}
		}
		i++;
	}
	stream.close();
	temp.close();
	remove(fname);
	rename("temp", fname);
	return l;
}
int div(const char* fname) {
	Money m; int l = 0;
	fstream stream(fname, ios::in);
	fstream temp("temp", ios::out);
	while (stream >> m) {
		temp << (m / 2);
		l++;
	}
	stream.close();
	temp.close();
	remove(fname);
	rename("temp", fname);
	return l;
}