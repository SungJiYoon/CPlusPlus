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
	cout << _name << "가 " << enemy._name << "을 공격해서 생명력이 " << enemy._health << "로 줄었음." << endl;
}

/*
void Monster::Attack(Golem& enemy) {
	cout << "Monster::Attack(Golem&)" << endl;

	enemy.GetDamage(_attack);

	cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄었음." << endl;
}

void Monster::Attack(Slime& enemy) {
	cout << "Monster::Attack(Slime&)" << endl;

	enemy.GetDamage(_attack);

	cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄었음." << endl;

}

void Monster::Attack(Goblin& enemy) {

	cout << "Monster::Attack(Slime&)" << endl;

	enemy.GetDamage(_attack);

	cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄었음." << endl;

}
*/



void Monster::Info() {
	cout << "이름: " << _name << endl;
	cout << "생명력: " << _health << endl;
	cout << "공격력: " << _attack << endl;
	cout << "방어력: " << _defense << endl;
}