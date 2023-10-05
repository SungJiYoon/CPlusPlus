#include "Dragon.h"
#include <iostream>

using namespace std;

Dragon::Dragon(string name, int health, int attack, int defense)
	: Monster(name, health, attack, defense) {}


void Dragon::GetDamage(int attack) {
	cout << "Monster::GetDamage(int)" << endl;
	int damage = attack - _defense;

	if (damage < 0) {
		damage = 0;
	}

	_health -= damage;
}

