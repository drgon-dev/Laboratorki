#include "error.h"
#include "List.h"
using namespace std;
int main() {
	try {
		List exmpl(2);
		List exmpl2(3);
		cout << exmpl + exmpl2;
	}
	catch (error e) {
		e.what();
	}
	return 0;
}