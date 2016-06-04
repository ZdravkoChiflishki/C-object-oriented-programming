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
public:
	virtual double getprice() const = 0;
	virtual void printProduct() const = 0;
	virtual ~Product() {};
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
	double getprice() const {
		return getpriceKG() / (1000 * getWeight());
	}
	void printProduct() const {
		cout << "Name of product: " << getName() << endl;
		cout << "Price for 1 Kilograme: " << getpriceKG() << endl;
		cout << "How much Does the Product weight: " << getWeight() << endl;
		cout << endl;
	};
};
class Beer : public Product {
private:
	char* name;
	char* marka;
	int price;
public:
	Beer(char* _name = " ", char* _marka = " ", int _price = 0) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		marka = new char[strlen(_marka) + 1];
		strcpy(marka, _marka);
		price = _price;
	}
	Beer(const Beer & other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		marka = new char[strlen(other.marka) + 1];
		strcpy(marka, other.marka);
		price = other.price;
	}
	Beer& operator=(const Beer& other) {
		if (this != &other) {
			delete[] name;
			delete[] marka;
			name = new char[strlen(other.getname()) + 1];
			strcpy(name, other.getname());
			marka = new char[strlen(other.marka) + 1];
			strcpy(marka, other.marka);
			price = other.getPrice();
		}
	}
	char* getname() const {
		return name;
	}
	char* getMarka() const {
		return marka;
	}
	int getPrice() const {
		return price;
	}
	~Beer() {
		delete[] name;
		delete[] marka;
	}
	double getprice() const {
		return getPrice();
	}
	void printProduct() const {
		cout << "Name of product: " << getname() << endl;
		cout << "Price for 1 Beer: " << getPrice() << endl;
		cout << "Marka na Birata: " << getMarka() << endl;
		cout << endl;
	};
};
int main()
{
	Fruit fruit1("Apple", 10, 10);
	Fruit fruit2("Orange", 5, 10);
	Fruit fruit3("Greipfruit", 4, 10);
	Fruit fruit4("Pineapple", 100, 200);
	Fruit fruit5("Juicy", 123, 345);

	Beer beer1("Kamenitza", "Stuklo", 2);
	Beer beer2("Ariana", "Stuklo", 3);
	Beer beer3("Heineken", "Stuklo", 4);
	Beer beer4("Amstel", "Stuklo", 5);
	Beer beer5("Tuborg", "Stuklo", 6);

	Product* producti[10] = { &fruit1,&fruit2,&fruit3,&fruit4,&fruit5,&beer1,&beer2,&beer3,&beer4,&beer5 };
	for (int i = 0; i < 10; i++)
	{
		producti[i]->printProduct();
	}
	system("pause");
	return 0;
}