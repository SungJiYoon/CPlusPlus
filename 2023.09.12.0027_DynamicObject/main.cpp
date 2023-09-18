#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Monster {
private:
    string _name;
    int _health;
    int _attack;
    int _defense;

public:
    // �⺻ �����ڸ� ȣ���ؼ� ��ü �迭�� ������ �մϴ�.
    Monster()
        : _name(""), _health(0), _attack(0), _defense(0)
    {
        cout << "Monster �⺻������" << endl;
    }

    // ���ڸ� �޴� �����ڸ� �ִ� ��쿣 ��ü �迭�� ���� �� ����.
    // ���ڸ� �޴� �����ڸ� ȣ���ؼ� ��ü �迭�� ���� �� ����.
    Monster(string name, int health, int attack, int defense)
        : _name(name), _health(health), _attack(attack), _defense(defense)
    {
        cout << "Monster ������" << endl;
    }

    ~Monster() {
        cout << "Monster �Ҹ���" << endl;
    }

    void Init(string name, int health, int attack, int defense) {
        _name = name;
        _health = health;
        _attack = attack;
        _defense = defense;
    }

    void Attack() {
        cout << _name << "�� �����Ѵ�." << endl;
    }

    void Defense() {
        cout << _name << "�� ����Ѵ�.";
    }

    void Info() {
        cout << "���͸�: " << _name << endl;
        cout << "�����: " << _health << endl;
        cout << "���ݷ�: " << _attack << endl;
        cout << "����: " << _defense << endl;
    }
};

int main() {
    // ��ü �迭
    char buff[100];

    // �������� �������, �������� ���� �� ����
    Monster array[10];   // ��ü �迭�� ������� �⺻�����ڰ� �ݵ�� �ʿ��մϴ�.
                    

    int length = sizeof(array) / sizeof(Monster);

    for (int i = 0; i < length; i++) {
        sprintf(buff, "Monster_%d", i);
        array[i].Init(buff, i * 20, i * 3, i * 2);

    }

    for (int i = 0; i < 10; i++) {
        array[i].Info();
    }


    return 0;
}