#pragma once
#include "Monster.h"
#include <string>

class Goblin :
	public Monster
{
private:
	int _fireAttackRegist;

public:
	Goblin(std::string name, int health, int attack, int defense, int fireAttackRegist);

	int GetFireAttackRegist();

	void GetDamage(int attack) override;
};

