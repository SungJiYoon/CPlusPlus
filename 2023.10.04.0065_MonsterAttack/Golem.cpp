#include "Golem.h"
#include <iostream>

using namespace std;


Golem::Golem(string name, int health, int attack, int defense, int physicalRegist)
	: Monster(name, health, attack, defense), _physicalRegist(physicalRegist) {}


int Golem::GetPhysicalRegist() {
	return _physicalRegist;
}

void Golem::GetDamage(int attack) {
	cout << "Golem::GetDamage(int)" << endl;
	int damage = attack - GetDefense() - _physicalRegist;

	if (damage < 0) {
		damage = 0;
	}

	SetHealth(GetHealth() - damage);	
}


