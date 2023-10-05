#include "Skull.h"
#include <iostream>

using namespace std;

Skull::Skull(std::string name, int health, int attack, int defense, int physicalAttackRegist)
	: Monster(name, health, attack, defense), _physicalAttackRegist(physicalAttackRegist) {}


void Skull::GetDamage(int attack) {
	cout << "Monster::GetDamage(int)" << endl;
	int damage = attack - _defense - _physicalAttackRegist;

	if (damage < 0) {
		damage = 0;
	}

	_health -= damage;
}
