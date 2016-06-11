#include<iostream>
using namespace std;
class Bag {
private:

public:
	Bag() {};
	Bag(const Bag & other) {};
	Bag & operator=(const Bag & other) {};
	~Bag() {};

};
class Set : public Bag{
private:

public:
	Set() {};
	Set(const Set & other) {};
	Set & operator=(const Set & other) {};
	~Set() {};
};
int main()
{
	return 0;
}