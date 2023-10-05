#pragma once
#include "Monster.h"
#include <string>

class Zombi :
	public Monster
{
public:
	Zombi(std::string name, int health, int attack, int defense);

	void GetDamage(int attack);
};

