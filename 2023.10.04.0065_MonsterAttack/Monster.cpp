#include "Monster.h"
#include <iostream>
#include "Golem.h"
#include "Slime.h"
#include "Goblin.h"


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

void Monster::GetDamage(int attack) {
	cout << "Monster::GetDamage(int)" << endl;
	int damage = attack - _defense;

	if (damage < 0) {
		damage = 0;
	}

	_health -= damage;
}

void Monster::Attack(Monster& enemy) {
	cout << "Monster::Attack(Monster&)" << endl;
	//enemy._health -= (_attack - enemy._defense);
	enemy.GetDamage(_attack);
	cout << _name << "�� " << enemy._name << "�� �����ؼ� ������� " << enemy._health << "�� �پ���." << endl;
}

/*
void Monster::Attack(Golem& enemy) {
	cout << "Monster::Attack(Golem&)" << endl;

	enemy.GetDamage(_attack);

	cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemy.GetHealth() << "�� �پ���." << endl;
}

void Monster::Attack(Slime& enemy) {
	cout << "Monster::Attack(Slime&)" << endl;

	enemy.GetDamage(_attack);

	cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemy.GetHealth() << "�� �پ���." << endl;

}

void Monster::Attack(Goblin& enemy) {

	cout << "Monster::Attack(Slime&)" << endl;

	enemy.GetDamage(_attack);

	cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemy.GetHealth() << "�� �پ���." << endl;

}
*/



void Monster::Info() {
	cout << "�̸�: " << _name << endl;
	cout << "�����: " << _health << endl;
	cout << "���ݷ�: " << _attack << endl;
	cout << "����: " << _defense << endl;
}