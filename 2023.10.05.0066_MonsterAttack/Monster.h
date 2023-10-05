#pragma once
#include <string>

// ���� �����Լ��� �ϳ��� �ִ� Ŭ������ �߻�Ŭ����
// �߻�Ŭ���� �ڽ��� ��ü�� ���� �� �����ϴ�.
// �׷��� �ڽ��� �ڽ��� ���������Լ��� ����� ���鵵�� ������ �� �ֽ��ϴ�.
class Monster
{
protected:
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

	virtual void GetDamage(int attack) = 0;	// ���������Լ� (�����ΰ� ���� �Լ�)

	void Attack(Monster& enemy);


	void Info();
};

