#pragma once
#include <string>
#include "Monster.h"

class Slime : public Monster
{
private:
	int _physicalRegist;   // �����������׷�

public:
	Slime(std::string name, int health, int attack, int defense, int physicalRegist);

	int GetPhysicalRegist();
};

