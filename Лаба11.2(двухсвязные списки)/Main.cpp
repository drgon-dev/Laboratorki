#include <iostream>
#include <fstream>
using namespace std;
bool is_created;
struct point
{
	string key;
	point* prev, * next;
};
point* first, * last;
void make_list(point*& first, point*& last)
{
	int n;
	cout << "Input the size of a list" << endl;
	cin >> n;
	cout << "key - ?" << endl;
	string s;
	cin >> s;

	point* p, * r;
	p = new (point);
	p->key = s; 
	p->prev = nullptr;
	p->next = nullptr;
	first = p;
	last = p;
	for (int i = 1; i < n; i++) 
	{
		r = new(point);  
		cout << "key - ?" << endl;
		cin >> s;

		r->key = s;
		p->next = r; 
		r->prev = p; 
		r->next = nullptr; 
		p = r; 
		last = p;
	}
}
void print_list(point* beg)
{
	if (beg == nullptr) 
	{
		cout << "The list is empty" << endl;
		return;
	}
	point* p = beg;
	while (p != nullptr) 
	{
		cout << p->key << " \t ";
		p = p->next;
	}
	cout << "\n";
}
void del_point(point*& beg, int k, point*& fin)
{
	k--;
	point* p = beg;
	if (k == 0) { 
		beg = beg->next; 
		if (beg == nullptr) {
			return;
		}
		beg->prev = nullptr;
		delete p;
		return;
	}
	for (int i = 0; i < k - 1 && p != nullptr; i++, p = p->next);
	if (p == nullptr || p->next == nullptr) return; 
	point* r = p->next;
	p->next = r->next;
	delete r;
	r = p->next;
	if (r) r->prev = p;
	else fin = p;
}
void add_point(point*& beg, int k, point*& fin) {
	point* p;
	string s;
	cout << "key - ?" << endl;
	cin >> s;
	k--;
	p = new(point);
	p->key = s;
	if (k == 0)
	{
		p->next = beg; 
		p->prev = nullptr; 
		beg->prev = p;
		beg = p; 
		return;
	}
	point* r = beg; 
	for (int i = 0; i < k - 1 && r->next != nullptr; i++, r = r->next); 

	p->next = r->next;
	if (r->next != nullptr) r->next->prev = p;
	else {
		p->next = nullptr;
		fin = p;
	};
	p->prev = r;
	r->next = p;
	return;
}
int find_key_index(point* beg) {
	string key_word;
	point* r = beg;
	int counter = 1;
	cout << "Input the key word" << endl;
	cin >> key_word;
	while (r) {
		if (r->key == key_word) return counter;
		r = r->next; 
		counter++;
	}
	cout << "not found" << endl;
	return NULL;
}
void delete_list(point*& beg, point*& fin) {
	point* p = beg;
	int counter = 1;
	while (p->next != nullptr) {
		p = p->next;
		counter++;
	}
	for (int i = counter; i > 0; i--) {
		del_point(beg, i, fin);
	}
	return;
}
void printINfile(point* beg, string path) {
	ofstream fout;
	fout.open(path);
	if (!fout.is_open()) { cout << "Error" << endl; }
	else {
		cout << "Information has been copied" << endl;
		point* p = beg;
		while (p != nullptr) {
			fout << p->key; 
			fout << "\n";
			p = p->next; 
		}
	}
	fout.close();
}
void readFROMfile(string path, point*& first, point*& last) {
	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) cout << "Error" << endl;
	else {
		cout << "Information has been restored" << endl;
		string word;
		point* p, * r;
		fin >> word; 
		p = new (point); 
		p->key = word;
		p->prev = nullptr;
		p->next = nullptr;
		first = p;

		while (!fin.eof()) {
			word = "";
			fin >> word;
			r = new(point);
			r->key = word;
			p->next = r;
			r->prev = p;
			r->next = nullptr;
			p = r;
			last = p;
		}
	}
	fin.close();
	return;
}
void menu(const int c) {
	string path = "myFile.txt";

	if ((c == 1 || c == 7) && is_created) { 
		cout << "List is already existing" << endl;
		return;
	}
	else if (c > 1 && c < 7 && !is_created) { 
		cout << "Create or restore a list" << endl;
		return;
	}
	switch (c) {
	case 1: {
		is_created = true;
		first = nullptr;
		last = nullptr;
		make_list(first, last);
		break;
	}
	case 2: {
		print_list(first);
		int num = find_key_index(first);
		int k;
		cout << "Input K" << endl;
		cin >> k;
		for (int i = 0; i < k; i++) {
			add_point(first, num + i, last);
		}
		num += k;
		for (int i = 0; i < k; i++) {
			add_point(first, num + i + 1, last);
		}
		print_list(first);
		break;
	}
	case 3: {
		print_list(first);
		int n;
		cout << "Position of an element you want to delete?" << endl;
		cin >> n;
		del_point(first, n, last);
		print_list(first);
		break;
	}
	case 4: {
		print_list(first);
		break;
	}
	case 5: {
		printINfile(first, path);
		break;
	}
	case 6: {
		cout << "List was destroyed" << endl;
		delete_list(first, last);
		is_created = false;
		break;
	}

	case 7: {
		readFROMfile(path, first = nullptr, last = nullptr);
		if (first == nullptr) cout << "There's nothing to restore" << endl;
		else is_created = true;
		break;
	}
	default: {
		cout << "Exiting from menu" << endl;
		delete_list(first, last);
		exit(777);
	}
	}
}
int main() {
	while (true) {
		system("pause");
		system("cls");
		cout << "1. Create a list" << endl;
		cout << "2. Add K elements before and after an element with key word" << endl;
		cout << "3. Delete an element" << endl;
		cout << "4. Print list" << endl;
		cout << "5. Write list in a file" << endl;
		cout << "6. Delete list" << endl;
		cout << "7. Read from file" << endl;
		cout << "Choose your option: ";
		int c;
		cin >> c;
		system("cls");
		menu(c);
	}
	return 0;
}