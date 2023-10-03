#include <iostream>
#include <string>

using namespace std;

// 몬스터
class Dragon {
private:
	string _name; 
	int _health; // 생명력
	int _attack; // 공격력
	int _defense; // 방어력

public:
	Dragon(string name, int health, int attack, int defense)
		: _name(name), _health(health), _attack(attack), _defense(defense){}

	string GetName() {
		return _name;
	}

	void Attack(Dragon& enemy) {
		enemy._health -= (_attack - enemy._defense);
		cout << _name << "가" << enemy._name << "을 공격해서 생명력이" << enemy._health << "로 줄었음." << endl;
	}

	void Info()
	{
		cout << "이름: " << _name << endl;
		cout << "생명력: " << _health << endl;
		cout << "공격력: " << _attack << endl;
		cout << "방어력: " << _defense << endl;
	}
};

int main()
{
	Dragon dragonA("dragonA", 100, 24, 10);
	Dragon dragonB("dragonB", 90, 20, 12);

	dragonA.Attack(dragonB);
	dragonB.Info();

	return 0;
}