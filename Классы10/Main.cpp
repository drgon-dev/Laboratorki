#include<iostream>
#include"Files.h"
using namespace std;
int main() {
	char filename[30];
	int ch, k,ad;
	do {
		cout << "1.New File";
		cout << "\n2.Print File";
		cout << "\n3.Delete element";
		cout << "\n4.Add element";
		cout << "\n5.Change element";
		cout << "\n6.Delete all elements < K";
		cout << "\n7.Add K elements after";
		cout << "\n8.Divide all elements by 2";
		cout << "\n0.Exit\n";
		cin >> ch;
		switch (ch) {
		case 1:
			cout << "File name:"; cin >> filename;
			k = makefile(filename);
			if (k < 0)
				cout << "ERROR: file is not created";
			break;
		case 2:
			cout << "File name:"; cin >> filename;
			k = printfile(filename);
			if (k < 0)
				cout << "ERROR:can't find file" << endl;
			break;
		case 3:
			cout << "File Name:"; cin >> filename;
			cout << "Number to delete:"; cin >> ad;
			k = delelem(filename, ad);
			if (k < 0)
				cout << "ERROR: can't read file";
			break;
		case 4:
			cout << "File Name:"; cin >> filename;
			cout << "Number to add:"; cin >> ad;
			k = adelem(filename, ad);
			if (k < 0)
				cout << "ERROR: can't read file";
			break;
		case 5:
			cout << "File Name:"; cin >> filename;
			cout << "Number to change:"; cin >> ad;
			k = chelem(filename, ad);
			if (k < 0)
				cout << "ERROR:can't find the element";
			break;
		case 6:
			cout << "File Name:"; cin >> filename;
			k = deles(filename);
			if (k < 0)
				cout << "ERROR:can't perform deletion";
			break;
		case 7:
			cout << "File Name:"; cin >> filename;
			cout << "Number to add:"; cin >> ad;
			k = adelems(filename, ad);
			if (k < 0)
				cout << "ERROR: can't add elements";
			break;
		case 8:
			cout << "File Name:"; cin >> filename;
			k = div(filename);
			if (k < 0)
				cout << "ERROR: can't find file";
			break;
		}
	} while (ch != 0);
	return 0;
}