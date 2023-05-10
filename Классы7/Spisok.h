template <class T>
class Spisok {
protected:
	T* dat;
	int size;
public:
	Spisok<T>() {
		dat = new T[1];
		size = 0;
	}
	Spisok<T>(int a) {
		dat = new T[a];
		size = a;
	}
	Spisok<T>(T a) {
		dat = new T[1];
		size = 1;
		dat[0] = a;
	}
	Spisok<T>(T a, int b) {
		dat = new T[b];
		size = b;
		for (int i=0; i < size; i++) {
			dat[i] = a;
		}
	}
	~Spisok<T>() {
		delete dat;
	}
	T& operator[](int index) {
		return dat[index];
	}
	int operator()() {
		return size;
	}
	Spisok<T> Add(T k) {
		Spisok<T> An(size + 1);
		for (int i = size + 1; i < (size-1); i++) {
			An.dat[i] = dat[i];
		}
		dat[size-1] = k;
	}
	Spisok<T> operator+(const Spisok<T>& b) {
		Spisok<T> An(size);
		for (int i = 0; i < size; i++) {
			An.dat[i] = dat[i] + b.dat[i];
		}
		return An;
	}
	friend istream& operator>>(istream& in, Spisok& a) {
		for (int i = 0; i < a.size; i++) {
			in >> a.dat[i];
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, const Spisok& a) {
		for (int i = 0; i < a.size; i++) {
			out << a.dat[i]<<" ";
		}
		return out;
	}
};