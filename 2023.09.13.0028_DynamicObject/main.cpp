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
        cout << "----------------------------" << endl;
        cout << "���͸�: " << _name << endl;
        cout << "�����: " << _health << endl;
        cout << "���ݷ�: " << _attack << endl;
        cout << "����: " << _defense << endl;
        cout << "----------------------------" << endl << endl;
    }
};


int main() {
    // ���� ��ü �迭
    int count = 0;
    char buff[30];

    cout << "���� ������ �������� �Է��ϼ���: ";
    cin >> count;

    Monster* parray = new Monster[count];   // ���� ��ü �迭�� ����

    for (int i = 0; i < count; i++) {
        sprintf(buff, "DynamicMonster_%d", i);
        parray[i].Init(buff, i * 10, i * 4, i * 3);
    }

    for (int i = 0; i < count; i++) {
        parray[i].Info();
    }

    delete[] parray;   // ���� ��ü�迭 ��ȯó�� 

    int* pint = new int;

    delete pint;


    return 0;
}