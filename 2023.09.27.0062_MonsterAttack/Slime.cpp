#include "Slime.h"
#include "Dragon.h"
#include "Ogre.h"
#include "Vampire.h"

#include <iostream>

using namespace std;

Slime::Slime(string name, int health, int attack, int defense, int physicalRegist)
    : _name(name), _health(health), _attack(attack), _defense(defense), _physicalRegist(physicalRegist) {}

string Slime::GetName() {
    return _name;
}

int Slime::GetHealth() {
    return _health;
}

void Slime::SetHealth(int value) {
    _health = value;
}

int Slime::GetDefense() {
    return _defense;
}

int Slime::GetPhysicalRegist() {
    return _physicalRegist;
}

void Slime::Attack(Slime& enemy) {
    enemy._health -= (_attack - enemy._defense);
    cout << _name << "�� " << enemy._name << "�� �����ؼ� ������� " << enemy._health << "�� �پ���." << endl;

}

void Slime::Attack(Dragon& enemy) {
    int health = enemy.GetHealth();
    int damage = _attack - enemy.GetDefense();

    if (damage < 0) {
        damage = 0;
    }

    health -= damage;
    enemy.SetHealth(health);
    cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemy.GetHealth() << "�� �پ���." << endl;

}

void Slime::Attack(Ogre& enemy) {
    int health = enemy.GetHealth();
    int damage = _attack - enemy.GetDefense();

    if (damage < 0) {
        damage = 0;
    }

    health -= damage;
    enemy.SetHealth(health);
    cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemy.GetHealth() << "�� �پ���." << endl;

}

void Slime::Attack(Vampire& enemy) {
    int health = enemy.GetHealth();
    int damage = _attack - enemy.GetDefense();

    if (damage < 0) {
        damage = 0;
    }

    health -= damage;
    enemy.SetHealth(health);
    cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemy.GetHealth() << "�� �پ���." << endl;
}

void Slime::Info() {
    cout << "�̸�: " << _name << endl;
    cout << "�����: " << _health << endl;
    cout << "���ݷ�: " << _attack << endl;
    cout << "����: " << _defense << endl;
}