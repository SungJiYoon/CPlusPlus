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
	cout << _name << "�� " << enemy._name << "�� �����ؼ� �������� " << enemy._health << "�� �پ���." << endl;
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

	cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� �������� " << enemy.GetHealth() << "�� �پ���." << endl;
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

	cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� �������� " << enemy.GetHealth() << "�� �پ���." << endl;

}



void Monster::Info() {
	cout << "�̸�: " << _name << endl;
	cout << "������: " << _health << endl;
	cout << "���ݷ�: " << _attack << endl;
	cout << "����: " << _defense << endl;
}