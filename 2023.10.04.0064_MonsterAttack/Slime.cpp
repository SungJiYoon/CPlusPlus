#include "Slime.h"
#include <iostream>

using namespace std;

Slime::Slime(string name, int health, int attack, int defense, int physicalRegist)
	: Monster(name, health, attack, defense), _physicalRegist(physicalRegist) {}


int Slime::GetPhysicalRegist() {
	return _physicalRegist;
}

void Slime::GetDamage(int attack) {
	cout << "Slime::GetDamage(int)" << endl;
	int damage = attack - GetDefense() - _physicalRegist;

	if (damage < 0) {
		damage = 0;
	}

	SetHealth(GetHealth() - damage);
}

