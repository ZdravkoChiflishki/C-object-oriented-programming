// PraktikumExammm2.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cstring>
#include <string>
using namespace std;


class Hero {
protected:
	string name;
	int health;
public:

	int getHealth() { return health; }
	void setHealth(int _health) {
		health = _health;
	}
	Hero(string _name) : name(_name) {
		health = 100;
	}

	string getName() const { return name; }

	virtual void attack(Hero* enemy) = 0;
	virtual void currentStatus() = 0;

	virtual void Presentation() = 0;
};


class Magician : public Hero {
private:
	int mana;
public:
	int getMana() { return mana; }
	Magician(string _name) : Hero(_name) {
		health = 100;
		mana = 200;
	}

	void currentStatus() {
		cout << "Current health: " << getHealth() << endl;
		cout << "Current mana: " << getMana() << endl;
	}

	void Presentation() {
		cout << "My name is" << getName() << endl;
	}

	void attack(Hero* enemy) {
		enemy->setHealth(enemy->getHealth() - this->getMana());
		this->mana = this->mana - 20;
	}



};

class Warrior :public Hero {
protected:
	int rage;
public:
	Warrior(string _name) : Hero(_name) {
		health = 120;
		rage = 0;
	}



	int getRage() { return rage; }
	int getHealth() { return health; }

	void currentStatus() {
		cout << "Current health: " << getHealth() << endl;
		cout << "Current rage: " << getRage() << endl;
	}

	void attack(Hero* enemy) {
		enemy->setHealth(enemy->getHealth() - (this->getRage() + 10));
		this->rage = this->rage + 20;
	}

	void Presentation() {
		cout << "My name is: " << getName() << endl;
	}

};

int main()
{
	Magician mag1("Emaka");
	Warrior war1("Peshaka");
	Warrior war2("Geshaka");
	Warrior war3("Zdravaka");
	Magician mag2("Vesaka");

	Hero* array[5] = { &mag1,&war1,&war2,&war3,&mag2 };
	array[0]->attack(array[1]);
	array[0]->attack(array[2]);
	array[0]->attack(array[3]);
	array[0]->attack(array[4]);
	array[0]->attack(array[1]);
	array[0]->attack(array[1]);
	array[0]->attack(array[1]);
	array[0]->attack(array[1]);
	array[1]->currentStatus();
	array[0]->currentStatus();
	array[0]->currentStatus();
	array[1]->Presentation();

	return 0;
}

