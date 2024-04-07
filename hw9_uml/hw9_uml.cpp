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
// ConcreteComponent (Human) - конкретный компонент определяет объект, на который возлагаются дополнительные обязанности
class Human: public Hero {

public:
	Human(): Hero("human") {
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
// Decorator (HeroDecorator) хранит ссылку на объект Component и определяет интерфейс, соответствующий интерфейсу Component
class HeroDecorator abstract : public Hero
{
protected:
	Hero* hero;
public:
	HeroDecorator(string n, Hero* hero) : Hero(n)
	{
		this->hero = hero;
	}
};
// ConcreteDecorator (HumanWarrior) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class HumanWarrior: public HeroDecorator {
public:
	HumanWarrior(Hero* hero) : HeroDecorator(hero->getName() + " warrior", hero) {}
	int getAttack() override {
		return hero->getAttack() + 20;
	}
	int getSpeed() override {
		return hero->getSpeed() + 10;
	}
	int getHealth() override {
		return hero->getHealth() + 50;
	}
	int getProtection() override {
		return hero->getProtection() + 20;
	}
};
// ConcreteDecorator (Swordtail) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class Swordtail : public HeroDecorator {
public:
	Swordtail(Hero* hero) : HeroDecorator(hero->getName() + " swordtail", hero) {}
	int getAttack() override {
		return hero->getAttack() + 40;
	}
	int getSpeed() override {
		return hero->getSpeed() - 10;
	}
	int getHealth() override {
		return hero->getHealth() + 50;
	}
	int getProtection() override {
		return hero->getProtection() + 40;
	}
};
// ConcreteDecorator (Archer) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class Archer : public HeroDecorator {
public:
	Archer(Hero* hero) : HeroDecorator(hero->getName() + " archer", hero) {}
	int getAttack() override {
		return hero->getAttack() + 20;
	}
	int getSpeed() override {
		return hero->getSpeed() + 20;
	}
	int getHealth() override {
		return hero->getHealth() + 50;
	}
	int getProtection() override {
		return hero->getProtection() + 10;
	}
};

// ConcreteDecorator (Rider) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class Rider : public HeroDecorator {
public:
	Rider(Hero* hero) : HeroDecorator(hero->getName() + " rider", hero) {}
	int getAttack() override {
		return hero->getAttack() - 10;
	}
	int getSpeed() override {
		return hero->getSpeed() + 40;
	}
	int getHealth() override {
		return hero->getHealth() + 200;
	}
	int getProtection() override {
		return hero->getProtection() + 100;
	}
};
// ConcreteComponent (Elf) - конкретный компонент определяет объект, на который возлагаются дополнительные обязанности
class Elf : public Hero {
public:
	Elf() : Hero("elf") {
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
// ConcreteDecorator (ElfWarrior) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class ElfWarrior : public HeroDecorator {
public:
	ElfWarrior(Hero* hero) : HeroDecorator(hero->getName() + " warrior", hero) {}
	int getAttack() override {
		return hero->getAttack() + 20;
	}
	int getSpeed() override {
		return hero->getSpeed() - 10;
	}
	int getHealth() override {
		return hero->getHealth() + 100;
	}
	int getProtection() override {
		return hero->getProtection() + 20;
	}
};
// ConcreteDecorator (ElfMagician) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class ElfMagician : public HeroDecorator {
public:
	ElfMagician(Hero* hero) : HeroDecorator(hero->getName() + " magician", hero) {}
	int getAttack() override {
		return hero->getAttack() + 10;
	}
	int getSpeed() override {
		return hero->getSpeed() + 10;
	}
	int getHealth() override {
		return hero->getHealth() - 50;
	}
	int getProtection() override {
		return hero->getProtection() + 10;
	}
};
// ConcreteDecorator (ElfCrossbowman) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class ElfCrossbowman : public HeroDecorator {
public:
	ElfCrossbowman(Hero* hero) : HeroDecorator(hero->getName() + " crossbowman", hero) {}
	int getAttack() override {
		return hero->getAttack() + 20;
	}
	int getSpeed() override {
		return hero->getSpeed() + 10;
	}
	int getHealth() override {
		return hero->getHealth() + 50;
	}
	int getProtection() override {
		return hero->getProtection() - 10;
	}
};

// ConcreteDecorator (BadMagician) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class BadMagician : public HeroDecorator {
public:
	BadMagician(Hero* hero) : HeroDecorator(hero->getName() + " bad magician", hero) {}
	int getAttack() override {
		return hero->getAttack() + 70;
	}
	int getSpeed() override {
		return hero->getSpeed() + 20;
	}
	int getHealth() override {
		return hero->getHealth() + 0;
	}
	int getProtection() override {
		return hero->getProtection() + 0;
	}
};

// ConcreteDecorator (GoodMagician) - конкретный декоратор возлагает дополнительные обязанности на компонент.
class GoodMagician : public HeroDecorator {
public:
	GoodMagician(Hero* hero) : HeroDecorator(hero->getName() + " good magician", hero) {}
	int getAttack() override {
		return hero->getAttack() + 50;
	}
	int getSpeed() override {
		return hero->getSpeed() + 30;
	}
	int getHealth() override {
		return hero->getHealth() + 100;
	}
	int getProtection() override {
		return hero->getProtection() + 30;
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

