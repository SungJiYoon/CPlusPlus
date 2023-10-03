#pragma once
#include <string>

class Ogre;
class Dragon;
class Vampire;

class Slime
{
private:
	std::string _name;
	int _health;
	int _attack;
	int _defense;
	int _physicalRegist;   // 물리공격저항력

public:
	Slime(std::string name, int health, int attack, int defense, int physicalRegist);

	int GetHealth();

	void SetHealth(int value);

	int GetDefense();

	int GetPhysicalRegist();

	std::string GetName();

	void Attack(Slime& enemy);
	void Attack(Dragon& enemy);
	void Attack(Ogre& enemy);
	void Attack(Vampire& enemy);

	void Info();
};

