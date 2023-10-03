#include "Vampire.h"
#include "Dragon.h"
#include "Ogre.h"
#include "Slime.h"

#include <iostream>

using namespace std;

Vampire::Vampire(string name, int health, int attack, int defense)
    : _name(name), _health(health), _attack(attack), _defense(defense) {}

string Vampire::GetName() {
    return _name;
}

int Vampire::GetHealth() {
    return _health;
}

void Vampire::SetHealth(int value) {
    _health = value;
}

int Vampire::GetDefense() {
    return _defense;
}

void Vampire::TakeHealth(int damage) {
    cout << _name << "�� " << damage << "�� ������� ���� " << endl;
    cout << "---���� �� Info()---" << endl;
    Info();  
    cout << "---���� �� Info()---" << endl;
    _health += damage;
    Info();
}

void Vampire::Attack(Vampire& enemy) {
    int damage = _attack - enemy._defense;
    enemy._health -= damage;
    cout << _name << "�� " << enemy._name << "�� �����ؼ� ������� " << enemy._health << "�� �پ���." << endl;
    
    TakeHealth(damage);
}

void Vampire::Attack(Dragon& enemy) {
    int health = enemy.GetHealth();
    int damage = _attack - enemy.GetDefense();

    if (damage < 0) {
        damage = 0;
    }

    health -= damage;
    enemy.SetHealth(health);
    cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemy.GetHealth() << "�� �پ���." << endl;
    
    TakeHealth(damage);
}

void Vampire::Attack(Ogre& enemy) {
    int health = enemy.GetHealth();
    int damage = _attack - enemy.GetDefense();

    if (damage < 0) {
        damage = 0;
    }

    health -= damage;
    enemy.SetHealth(health);
    cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemy.GetHealth() << "�� �پ���." << endl;

    TakeHealth(damage);
}

void Vampire::Attack(Slime& enemy) {
    int health = enemy.GetHealth();
    int damage = _attack - enemy.GetDefense() - enemy.GetPhysicalRegist();

    if (damage < 0) {
        damage = 0;
    }

    health -= damage;
    enemy.SetHealth(health);
    cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemy.GetHealth() << "�� �پ���." << endl;

    TakeHealth(damage);
}

void Vampire::Info() {
    cout << "�̸�: " << _name << endl;
    cout << "�����: " << _health << endl;
    cout << "���ݷ�: " << _attack << endl;
    cout << "����: " << _defense << endl;
}