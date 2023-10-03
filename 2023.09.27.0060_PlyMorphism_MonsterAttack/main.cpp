#include <iostream>
#include <string>

using namespace std;

// ����
class Dragon {
private:
	string _name; 
	int _health; // �����
	int _attack; // ���ݷ�
	int _defense; // ����

public:
	Dragon(string name, int health, int attack, int defense)
		: _name(name), _health(health), _attack(attack), _defense(defense){}

	string GetName() {
		return _name;
	}

	void Attack(Dragon& enemy) {
		enemy._health -= (_attack - enemy._defense);
		cout << _name << "��" << enemy._name << "�� �����ؼ� �������" << enemy._health << "�� �پ���." << endl;
	}

	void Info()
	{
		cout << "�̸�: " << _name << endl;
		cout << "�����: " << _health << endl;
		cout << "���ݷ�: " << _attack << endl;
		cout << "����: " << _defense << endl;
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