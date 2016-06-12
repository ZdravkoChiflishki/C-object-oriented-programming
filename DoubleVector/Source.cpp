#include<iostream>
#include<stdlib.h>
using namespace std;
class DoubleVec {
private:
	double *vector;
	int size;
protected:
	int lower;
	int upper;
public:
	DoubleVec(int = 1);
	~DoubleVec();
	DoubleVec(const DoubleVec& other);
	DoubleVec& operator=(const DoubleVec& other);
	double& operator[](int);
	int lowerbound() const;
	int upperbound() const;
};
DoubleVec::DoubleVec(int s) {
	if (s <= 0) {
		cout << "Невалидна размерност на вектор!\n";
		exit(1);
	}
	lower = 0;
	upper = s - 1;
	size = s;
	vector = new double[s];
	if (!vector) {
		cout << "Грешка при заделянето на памет!\n";
		exit(1);
	}
}
DoubleVec::~DoubleVec() {
	delete[] vector;
}
DoubleVec::DoubleVec(const DoubleVec& other) {
	size = other.size;
	vector = new double[size];
	if (!vector) {
		cout << "Грешка при заделянето на памет!\n";
		exit(1);
	}
	for (int i = 0; i < size; i++) {
		vector[i] = other.vector[i];
	}
	lower = other.lower;
	upper = other.upper;
}
DoubleVec& DoubleVec::operator=(const DoubleVec& other) {
	if (this != &other) {
		delete[] vector;
		size = other.size;
		vector = new double[size];
		if (!vector) {
			cout << "Грешка при заделянето на памет!\n";
			exit(1);
		}
		for (int i = 0; i < size; i++) {
			vector[i] = other.vector[i];
		}
		lower = other.lower;
		upper = other.upper;
	}
	return *this;
}
double& DoubleVec::operator[](int i) {
	if (i<0 || i > upper - lower) {
		cout << "Некоректен индекс!\n";
		exit(1);
	}
	return vector[i];
}
int DoubleVec::lowerbound() const {
	return lower;
}
int DoubleVec::upperbound() const {
	return upper;
}
class DoubleVector : public DoubleVec {
public:
	DoubleVector(int, int);
	double& operator[](int);
};
DoubleVector::DoubleVector(int low, int upp) : DoubleVec(upp - low + 1) {
	lower = low;
	upper = upp;
}
double& DoubleVector::operator[](int i) {
	return DoubleVec::operator[](i - lower);
}

int main()
{
	DoubleVec u(4);
	int i;
	for (i = u.lowerbound(); i <= u.upperbound(); i++) {
		cout << "> ";
		cin >> u[i];
	}
	for (i = u.lowerbound(); i <= u.upperbound(); i++)
		cout << u[i] << " ";
	cout << endl;
	DoubleVector v(26, 35);
	for (i = v.lowerbound(); i <= v.upperbound(); i++) {
		cout << "> ";
		cin >> v[i];
	}
	for (i = v.lowerbound(); i <= v.upperbound(); i++)
		cout << v[i] << " ";
	system("pause");
	return 0;
}