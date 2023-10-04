#pragma once
#include <string>
#include "Monster.h"

class Slime : public Monster
{
private:
	int _physicalRegist;   // 물리공격저항력

public:
	Slime(std::string name, int health, int attack, int defense, int physicalRegist);

	int GetPhysicalRegist();
};

