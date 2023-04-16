#include <iostream>
using namespace std;
class kvit {
private:
	int number;
	string data;
	double sum;
public:
	kvit() {
		number = 0;
		data = "";
		sum = 0;
	}
	kvit(int innumber, string indata, double insum) {
		number = innumber;
		data = indata;
		sum = insum;
	}
	kvit(const kvit& d) {
		number = d.number;
		data = d.data;
		sum = d.sum;
	}
	void chnum(int inp) {
		number = inp;
	}
	void chdata(string dat) {
		data = dat;
	}
	void chsum(double su) {
		sum = su;
	}
	int numberc() {
		return number;
	}
	string datac() {
		return data;
	}
	double sumc() {
		return sum;
	}
	~kvit() {

	}
};
