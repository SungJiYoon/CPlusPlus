#pragma once
#include "Monster.h"
#include <string>

class Skull :
	public Monster
{
private:
	int _physicalAttackRegist;	// ���� ���� ���׷�

public:
	Skull(std::string name, int health, int attack, int defense, int physicalAttackRegist);

	void GetDamage(int attack);


};

