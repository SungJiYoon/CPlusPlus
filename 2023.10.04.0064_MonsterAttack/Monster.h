#pragma once
#include <string>

class Golem;
class Slime;

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

	void GetDamage(int attack);

	void Attack(Monster& enemy);

	void Attack(Golem& enemy);

	void Attack(Slime& enemy);


	void Info();
};

