// hw9_uml.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;



class Hero {
protected:
	string name;
public:
	Hero(string n) {
		name = n;
	}
	string getName() {
		return name;
	}

	virtual int getAttack() abstract;
	virtual int getSpeed() abstract;
	virtual int getHealth() abstract;
	virtual int getProtection() abstract;

};
// ConcreteComponent (Human) - конкретный компонент определ€ет объект, на который возлагаютс€ дополнительные об€занности
class Human: public Hero {

public:
	Human(): Hero("human") {
	}

	Human(string n): Hero(n) {
		name = n;
	}

	int getAttack() override {
		return 20;
	}

	int getSpeed() override {
		return 20;
	}

	int getHealth() override {
		return 150;
	}

	int getProtection() override {
		return 0;
	}

	
};
// Decorator (HeroDecorator) хранит ссылку на объект Component и определ€ет интерфейс, соответствующий интерфейсу Component
class HumanDecorator abstract : public Human
{
protected:
	Human* human;
public:
	HumanDecorator(string n, Hero* hero) : Human(n)
	{
		this->human = human;
	}
};


// Decorator (HeroDecorator) хранит ссылку на объект Component и определ€ет интерфейс, соответствующий интерфейсу Component
class ElfDecorator abstract : public Elf
{
protected:
	Elf* elf;
public:
	ElfDecorator(string n, Hero* hero) : Elf(n)
	{
		this->elf = elf;
	}
};
// ConcreteDecorator (HumanWarrior) - конкретный декоратор возлагает дополнительные об€занности на компонент.
class HumanWarrior: public HumanDecorator {
public:
	HumanWarrior(Hero* hero) : HumanDecorator(hero->getName() + " warrior", hero) {}
	int getAttack() override {
		return human->getAttack() + 20;
	}
	int getSpeed() override {
		return human->getSpeed() + 10;
	}
	int getHealth() override {
		return human->getHealth() + 50;
	}
	int getProtection() override {
		return human->getProtection() + 20;
	}
};
// ConcreteDecorator (Swordtail) - конкретный декоратор возлагает дополнительные об€занности на компонент.
class Swordtail : public HumanDecorator {
public:
	Swordtail(Hero* hero) : HumanDecorator(hero->getName() + " swordtail", hero) {}
	int getAttack() override {
		return human->getAttack() + 40;
	}
	int getSpeed() override {
		return human->getSpeed() - 10;
	}
	int getHealth() override {
		return human->getHealth() + 50;
	}
	int getProtection() override {
		return human->getProtection() + 40;
	}
};
// ConcreteDecorator (Archer) - конкретный декоратор возлагает дополнительные об€занности на компонент.
class Archer : public HumanDecorator {
public:
	Archer(Hero* hero) : HumanDecorator(hero->getName() + " archer", hero) {}
	int getAttack() override {
		return human->getAttack() + 20;
	}
	int getSpeed() override {
		return human->getSpeed() + 20;
	}
	int getHealth() override {
		return human->getHealth() + 50;
	}
	int getProtection() override {
		return human->getProtection() + 10;
	}
};

// ConcreteDecorator (Rider) - конкретный декоратор возлагает дополнительные об€занности на компонент.
class Rider : public HumanDecorator {
public:
	Rider(Hero* hero) : HumanDecorator(hero->getName() + " rider", hero) {}
	int getAttack() override {
		return human->getAttack() - 10;
	}
	int getSpeed() override {
		return human->getSpeed() + 40;
	}
	int getHealth() override {
		return human->getHealth() + 200;
	}
	int getProtection() override {
		return human->getProtection() + 100;
	}
};
// ConcreteComponent (Elf) - конкретный компонент определ€ет объект, на который возлагаютс€ дополнительные об€занности
class Elf : public Hero {
public:
	Elf() : Hero("elf") {
	}

	Elf(string n) : Hero(n) {
		name = n;
	}

	int getAttack() override {
		return 15;
	}

	int getSpeed() override {
		return 30;
	}

	int getHealth() override {
		return 100;
	}

	int getProtection() override {
		return 0;
	}
};
// ConcreteDecorator (ElfWarrior) - конкретный декоратор возлагает дополнительные об€занности на компонент.
class ElfWarrior : public ElfDecorator {
public:
	ElfWarrior(Hero* hero) : ElfDecorator(hero->getName() + " warrior", hero) {}
	int getAttack() override {
		return elf->getAttack() + 20;
	}
	int getSpeed() override {
		return elf->getSpeed() - 10;
	}
	int getHealth() override {
		return elf->getHealth() + 100;
	}
	int getProtection() override {
		return elf->getProtection() + 20;
	}
};
// ConcreteDecorator (ElfMagician) - конкретный декоратор возлагает дополнительные об€занности на компонент.
class ElfMagician : public ElfDecorator {
public:
	ElfMagician(Hero* hero) : ElfDecorator(hero->getName() + " magician", hero) {}
	int getAttack() override {
		return elf->getAttack() + 10;
	}
	int getSpeed() override {
		return elf->getSpeed() + 10;
	}
	int getHealth() override {
		return elf->getHealth() - 50;
	}
	int getProtection() override {
		return elf->getProtection() + 10;
	}
};
// ConcreteDecorator (ElfCrossbowman) - конкретный декоратор возлагает дополнительные об€занности на компонент.
class ElfCrossbowman : public ElfDecorator {
public:
	ElfCrossbowman(Hero* hero) : ElfDecorator(hero->getName() + " crossbowman", hero) {}
	int getAttack() override {
		return elf->getAttack() + 20;
	}
	int getSpeed() override {
		return elf->getSpeed() + 10;
	}
	int getHealth() override {
		return elf->getHealth() + 50;
	}
	int getProtection() override {
		return elf->getProtection() - 10;
	}
};

// ConcreteDecorator (BadMagician) - конкретный декоратор возлагает дополнительные об€занности на компонент.
class BadMagician : public ElfDecorator {
public:
	BadMagician(Hero* hero) : ElfDecorator(hero->getName() + " bad magician", hero) {}
	int getAttack() override {
		return elf->getAttack() + 70;
	}
	int getSpeed() override {
		return elf->getSpeed() + 20;
	}
	int getHealth() override {
		return elf->getHealth() + 0;
	}
	int getProtection() override {
		return elf->getProtection() + 0;
	}
};

// ConcreteDecorator (GoodMagician) - конкретный декоратор возлагает дополнительные об€занности на компонент.
class GoodMagician : public ElfDecorator {
public:
	GoodMagician(Hero* hero) : ElfDecorator(hero->getName() + " good magician", hero) {}
	int getAttack() override {
		return elf->getAttack() + 50;
	}
	int getSpeed() override {
		return elf->getSpeed() + 30;
	}
	int getHealth() override {
		return elf->getHealth() + 100;
	}
	int getProtection() override {
		return elf->getProtection() + 30;
	}
};

void client(Hero* hero) {
	char s[100];
	sprintf_s(s, "name: %s  attack: %d  speed: %d  health: %d  protection: %d", hero->getName().c_str(), hero->getAttack(), hero->getSpeed(), hero->getHealth(), hero->getProtection());
	cout << s << endl;
}
int main()
{
	Hero* hero = new Human();
	hero = new Swordtail(hero);
	client(hero);
	delete hero;

	Hero* hero1 = new Elf();
	hero1 = new BadMagician(hero1);
	client(hero1);
	delete hero1;
}

