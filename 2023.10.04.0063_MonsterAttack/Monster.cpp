#include "Monster.h"
#include <iostream>
#include "Golem.h"
#include "Slime.h"


using namespace std;


Monster::Monster(string name, int health, int attack, int defense)
	: _name(name), _health(health), _attack(attack), _defense(defense) {}

string Monster::GetName() {
	return _name;
}

int Monster::GetHealth() {
	return _health;
}

void Monster::SetHealth(int value) {
	_health = value;
}

int Monster::GetDefense() {
	return _defense;
}

void Monster::Attack(Monster& enemy) {
	cout << "Monster::Attack(Monster&)" << endl;
	enemy._health -= (_attack - enemy._defense);
	cout << _name << "가 " << enemy._name << "을 공격해서 생명력이 " << enemy._health << "로 줄었음." << endl;
}

void Monster::Attack(Golem& enemy) {
	cout << "Monster::Attack(Golem&)" << endl;
	int health = enemy.GetHealth();

	int damage = _attack - enemy.GetDefense() - enemy.GetPhysicalRegist();

	if (damage < 0) {
		damage = 0;
	}

	health -= damage;

	enemy.SetHealth(health);

	cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄었음." << endl;
}

void Monster::Attack(Slime& enemy) {
	cout << "Monster::Attack(Slime&)" << endl;
	int health = enemy.GetHealth();

	int damage = _attack - enemy.GetDefense() - enemy.GetPhysicalRegist();

	if (damage < 0) {
		damage = 0;
	}

	health -= damage;

	enemy.SetHealth(health);

	cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄었음." << endl;

}



void Monster::Info() {
	cout << "이름: " << _name << endl;
	cout << "생명력: " << _health << endl;
	cout << "공격력: " << _attack << endl;
	cout << "방어력: " << _defense << endl;
}