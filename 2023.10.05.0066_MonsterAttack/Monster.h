#pragma once
#include <string>

// 순수 가상함수가 하나라도 있는 클래스를 추상클래스
// 추상클래스 자신의 객체를 만들 수 없습니다.
// 그러나 자식이 자신의 순수가상함수를 만드시 만들도록 강제할 수 있습니다.
class Monster
{
protected:
	std::string _name;
	int _health;	// 생명력
	int _attack;	// 공격력
	int _defense;	// 방어력

public:
	Monster(std::string name, int health, int attack, int defense);

	std::string GetName();

	int GetHealth();

	void SetHealth(int value);

	int GetDefense();

	virtual void GetDamage(int attack) = 0;	// 순수가상함수 (구현부가 없는 함수)

	void Attack(Monster& enemy);


	void Info();
};

