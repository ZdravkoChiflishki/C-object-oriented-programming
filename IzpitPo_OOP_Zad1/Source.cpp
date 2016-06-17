/*Имате магазин за тениски и искате работниците, които ползват програмата ви, да могат да проверяват за тениски в склада.
За всяка тениска ние знаем каква марка е, колко струва, какъв размер е и дали е мъжка или женска.
Критериите, по които вашите служители ще искат да търсят тениските, са :
- Всички тениски с дадена марка.
- Всички мъжки/женски тениски с даден размер.
- Всички тениски, които са под дадена цена.
- Дали съществува тениска с марка "...." , размер "..." и М/Ж.
Задачата да се реализира с два класа, представящи магазин и тениска.
*/
#include<iostream>
#include<cstring>
using namespace std;
enum MF { male, female };
class T_Shirt {
private:
	char *marka;
	int price;
	int size;
public:
	//constructor
	T_Shirt(char* _marka = " ", int _price = 0, int _size = 0) : price(_price), size(_size) {
		marka = new char[strlen(_marka) + 1];
		strcpy(marka, _marka);
	};
	//copy constructor
	T_Shirt(const T_Shirt & other) {
		marka = new char[strlen(other.marka) + 1];
		strcpy(marka, other.marka);
		price = other.price;
		size = other.size;
	}
	//opretor=
	/*
	T_Shirt& operator=(const T_Shirt& other){
	if (this != &other)
	{
	marka = new char[strlen(other.marka) + 1];
	strcpy(marka, other.marka);
	price = other.price;
	size = other.size;
	}
	return *this;
	}
	*/
	//Destructor
	~T_Shirt() {
		delete[] marka;
	}
	//getter
	char *getMarka() const {
		return marka;
	}
	//getter
	int getPrice() const {
		return price;
	}
	//getter
	int getSize() const {
		return size;
	}
	void printT_Shirt() const {
		cout << "Marka na T_Shirt:" << getMarka() << endl;
		cout << "Male or Female: " << "MALE" << endl;
		cout << "Cena na T_Shirt:" << getPrice() << endl;
		cout << "Razmer na T_Shirt:" << getSize() << endl;
	}
};
class Magazine {
private:
	T_Shirt teniski[100];
	int broiTeniski;
public:
	Magazine() : broiTeniski(0) {};
	Magazine(T_Shirt _teniski[], int _broiTeniski) : broiTeniski(_broiTeniski) {
		for (int i = 0; i < broiTeniski; i++) {
			teniski[i] = _teniski[i];
		}
	};
	~Magazine() {};
	void addTeniski(T_Shirt& other) {
		teniski[broiTeniski++] = other;
	}
	void SearchByMarka(const char value[]) {
		for (int i = 0; i < broiTeniski; i++) {
			if (strcmp(teniski[i].getMarka(), value) == 0) {
				teniski[i].printT_Shirt();
			}
			cout << endl;
		}
	}
	void SearchBelowPrice(int somePrice) {
		for (int i = 0; i < broiTeniski; i++) {
			if (teniski[i].getPrice() <= somePrice)
			{
				teniski[i].printT_Shirt();
			}
			cout << endl;
		}

	}
	void SearchByMaleOrFemaleSize(int someSize) {
		for (int i = 0; i < broiTeniski; i++)
		{
			if (teniski[i].getSize() == someSize) {
				teniski[i].printT_Shirt();
			}
			cout << endl;
		}
	}
	void printMagazine() const {
		for (int i = 0; i < broiTeniski; i++) {
			teniski[i].printT_Shirt();
		}
		cout << endl;
	}
};
int main()
{
	T_Shirt a("Bqla_Teniska", 20, 3);
	T_Shirt b("Cherna_Teniska", 30, 4);
	T_Shirt c("Sinq_Teniska", 40, 5);
	Magazine TeniskiteNaZdravko;
	TeniskiteNaZdravko.addTeniski(a);
	TeniskiteNaZdravko.addTeniski(b);
	TeniskiteNaZdravko.addTeniski(c);
	TeniskiteNaZdravko.SearchBelowPrice(30);
	TeniskiteNaZdravko.SearchByMaleOrFemaleSize(5);
	TeniskiteNaZdravko.SearchByMarka("Cherna_Teniska");
	system("pause");
	return 0;
}
