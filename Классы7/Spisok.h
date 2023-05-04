//size приравнен к индексам массива
template <class T>
class Spisok {
protected:
	T* dat;
	int size;
public:
	Spisok() {
		dat = new T[0];
		size = -1;
	}
	Spisok(T a) {
		dat = new T[1];
		size = 0;
		dat[0] = a;
	}
	Spisok(T a, int b) {
		dat = new T[b];
		size = b-1;
		for (int i=0; i <= size; i++) {
			dat[i] = a;
		}
	}
	~Spisok() {
		delete dat;
	}
	T& operator[](int index) {
		return dat[index];
	}
	int operator()() {
		return size;
	}
	Spisok Add(T k) {
		Spisok An(k,size + 1);
		for (int i = size + 1; i <= size; i++) {
			An.dat[i] = dat[i];
		}
		dat[size + 1] = k;
	}
	Spisok operator+(Spisok b) {
		Spisok An();
		for (int i = 0; i <= size; i++) {
			An.size++;
			An.dat[i] = dat[i] + b.dat[i];
		}
		return An;
	}
	friend ostream& operator<<(ostream& out, const Spisok& a) {
		for (int i = 0; i <= a.size; i++) {
			out << a.dat[i]<<" ";
		}
		return out;
	}
};