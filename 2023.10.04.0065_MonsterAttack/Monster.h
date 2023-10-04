#pragma once
#include <string>

class Golem;
class Slime;
class Goblin;

class Monster
{
private:
	std::string _name;
	int _health;	// �����
	int _attack;	// ���ݷ�
	int _defense;	// ����

public:
	Monster(std::string name, int health, int attack, int defense);

	std::string GetName();

	int GetHealth();

	void SetHealth(int value);

	int GetDefense();

	virtual void GetDamage(int attack);	// �����Լ�

	void Attack(Monster& enemy);

	/*
	void Attack(Golem& enemy);

	void Attack(Slime& enemy);

	void Attack(Goblin& enemy);
	*/


	void Info();
};

