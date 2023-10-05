#pragma once
#include "Monster.h"
#include <string>

class Skull :
	public Monster
{
private:
	int _physicalAttackRegist;	// 물리 공격 저항력

public:
	Skull(std::string name, int health, int attack, int defense, int physicalAttackRegist);

	void GetDamage(int attack);


};

