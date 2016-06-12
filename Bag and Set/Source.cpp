#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
class Bag
{
protected:
	int *plurality, count = 0, size = 100;
public:
	Bag();
	void NewBag();
	void AddDigit(int n);
	void RemoveElem(int index);
	void DeleteByVal(int val);
	void SectionBag(Bag &other);
	void PrintArray();
	void BagUnion(Bag &thiss, Bag &other);
	void BagDiffrence(Bag &thiss, Bag &other);
	void PrintBagLength();
};
Bag::Bag() {
	plurality = new int[size];
	if (plurality = nullptr) {
		cout << "Грешка при заделянето на памет";
		exit(1);
	}
}
void Bag::NewBag() {
	int *Pointer = plurality;
	plurality = new int[size];
	if (plurality = nullptr) {
		cout << "Грешка при заделянето на памет";
		exit(1);
	}
	for (int i = 0; i < size; i++) plurality[i] = Pointer[i];
	delete Pointer;
}
void Bag::AddDigit(int m) {
	plurality[count] = m;
	count++;
}
void Bag::RemoveElem(int index) {
	for (int i = index; i < count; i++) plurality[i] = plurality[i + 1];
	count--;
}
void Bag::DeleteByVal(int val)
{
	for (size_t i = 0; i < count; i++)
	{
		if (plurality[i] == val) {
			RemoveElem(i);
			break;
		}
	}
}
void Bag::SectionBag(Bag &other) {
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = 0; j < other.count; j++)
		{
			if (plurality[i] == other.plurality[j])
			{
				cout << plurality[i];
			}
			DeleteByVal(other.plurality[j]);
			DeleteByVal(plurality[i]);
			break;
		}
	}
}
void Bag::PrintArray() {
	for (size_t i = 0; i < count; i++)
	{
		cout << plurality[i] << " ";
	}
}
void Bag::BagUnion(Bag &thiss, Bag &other)
{
	thiss.PrintArray();
	thiss.PrintArray();
}
void Bag::BagDiffrence(Bag &thiss, Bag &other)
{
	for (size_t i = 0; i < thiss.count; i++)
	{
		cout << thiss.plurality[i] - other.plurality[i];
	}
}
void Bag::PrintBagLength()
{
	cout << "The Lenght Of The Bag is: " << count << endl;
}
class Set : protected Bag {
protected:
	int *_plurality, count = 0, size = 100;
public:
	Set();
	void createSet();
	void addElement(int n);
	bool checkForRepeats(int N);
	void Sechenie(Set &other);
	void printSetLenght();
	void printSet();
	void Obedinenie(Set &thiss, Set &other);
	void Razlika(Set &thiss, Set &other);
};
Set::Set() {
	_plurality = new int[size];
}
void Set::createSet() {
	int *copy = _plurality;
	_plurality = new int[size];
	for (int i = 0; i < size; i++)
	{
		_plurality[i] = copy[i];
	}
	delete copy;
}
void Set::addElement(int n) {
	if (checkForRepeats(n) == false)
	{
		this->_plurality[count] = n;
		count++;
	}
	else
	{
		cout << "This element is already in the set" << endl;
	}
}
bool Set::checkForRepeats(int N)
{
	for (size_t i = 0; i <= count; i++)
	{
		if (_plurality[i] == N)
		{
			return true;
		}
		else return false;
	}
}
void Set::Sechenie(Set &other) {
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = 0; j < other.count; j++)
		{
			if (_plurality[i] == other._plurality[j])
			{
				cout << _plurality[i];
			}
			DeleteByVal(other._plurality[j]);
			DeleteByVal(_plurality[i]);
			break;
		}
	}
}
void Set::printSetLenght()
{
	cout << "The Lenght Of The Set is: " << count << endl;
}
void Set::printSet() {
	for (size_t i = 0; i < count; i++)
	{
		cout << _plurality[i] << " ";
	}
}
void Set::Obedinenie(Set &thiss, Set &other)
{
	thiss.PrintArray();
	thiss.PrintArray();
}
void Set::Razlika(Set &thiss, Set &other)
{
	for (size_t i = 0; i < thiss.count; i++)
	{
		cout << thiss._plurality[i] - other._plurality[i];
	}
}
int main()
{
	Set set1;
	set1.createSet();
	set1.printSet();
	set1.addElement(4);
	set1.addElement(3);
	set1.printSet();
	set1.printSetLenght();
	system("pause");
	return 0;
}