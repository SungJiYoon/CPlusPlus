#include "Goblin.h"
#include <iostream>

using namespace std;


Goblin::Goblin(std::string name, int health, int attack, int defense, int fireAttackRegist) 
	: Monster(name, health, attack, defense), _fireAttackRegist(fireAttackRegist)
{

}

int Goblin::GetFireAttackRegist() {
	return _fireAttackRegist;
}

void Goblin::GetDamage(int attack) {
	cout << "Goblin::GetDamage(int)" << endl;
	int damage = attack - GetDefense() - _fireAttackRegist;

	if (damage < 0) {
		damage = 0;
	}

	SetHealth(GetHealth() - damage);
}