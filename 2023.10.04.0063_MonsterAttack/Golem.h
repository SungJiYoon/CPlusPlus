#pragma once
#include <string>
#include "Monster.h"


class Golem : public Monster
{
private:
	int _physicalRegist;	// 물리 공격 저항력

public:
	Golem(std::string name, int health, int attack, int defense, int physicalRegist);

	int GetPhysicalRegist();
};

