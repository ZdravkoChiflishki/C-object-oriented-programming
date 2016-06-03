/*Създайте клас Product, представляващ интерфейс на продукт в хранителен магазин, със следните операции:
намиране на цена на продукта , извеждане на данни за продукта
Създайте клас Fruit, представящ плод с вид (например, ябълка, портокал), тегло в грамове и цена на килограм.
Fruit трябва да имплементира интерфейса Product, като изчислява цената на конкретния плод.
Създайте клас Beer, представящ бира, описана с вида на контейнера
(например, стъклена бутилка, пластмасова бутилка, кен), марка и цена.
Beer трябва да имплементира интерфейса Product.
Всички низове да бъдат динамично заделени масиви от символи.
За всички класове да се подсигури правилното функциониране на "голямата четворка".
Да се създадат 5 обекта от тип Fruit, представящи 5 различни плода, и 5 обекта от тип Beer,
представящи 5 различни бири. Да се създаде масив, съдържащ указатели към всички създадени обекти (5-те плода и 5-те бири).
Масивът да се обходи с цикъл, като на всяка итерация да се извеждат данните за съответния продукт.*/
#include<iostream>
#include<cstring>

using namespace std;

class Product {
	virtual int getprice(char name) const = 0;
	virtual	void printProduct(char name) const = 0;
};
class Fruit : public Product {
private:
	char* name;
	int weight;
	int priceKG;
public:
	Fruit(char* _name = " ", int _weight = 0, int _priceKG = 0)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		weight = _weight;
		priceKG = _priceKG;
	}
	Fruit(const Fruit & other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		weight = other.weight;
		priceKG = other.priceKG;
	}
	~Fruit() {
		delete[] name;
	}
	Fruit & operator=(const Fruit& other) {
		if (this != &other)
		{
			delete[] name;
			name = new  char[strlen(other.getName()) + 1];
			strcpy(name, other.getName());
			weight = other.getWeight();
			priceKG = other.getpriceKG();
		}
		return *this;
	}
	char* getName() const {
		return name;
	}
	int getWeight() const {
		return weight;
	}
	int getpriceKG() const {
		return priceKG;
	}
	void printproduct(char name) const {

	}
};
class Beer : public Product {
private:
	char* name;
	int price;
public:
	Beer(char* _name = " ", int _price = 0) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		price = _price;
	}
	Beer(const Beer & other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		price = other.price;
	}
	Beer& operator=(const Beer& other) {
		if (this != &other) {
			delete[] name;
			name = new char[strlen(other.getname()) + 1];
			strcpy(name, other.getname());
			price = other.getPrice();
		}
	}
	char* getname() const {
		return name;
	}
	int getPrice() const {
		return price;
	}
	~Beer() {
		delete[] name;
	}


};
int main()
{
	return 0;
}