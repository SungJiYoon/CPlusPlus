#include "Dragon.h"
#include "Ogre.h"
#include "Slime.h"
#include "Vampire.h"

#include <iostream>

using namespace std;

Dragon::Dragon(string name, int health, int attack, int defense)
    : _name(name), _health(health), _attack(attack), _defense(defense) {}

string Dragon::GetName() {
    return _name;
}

int Dragon::GetHealth() {
    return _health;
}

void Dragon::SetHealth(int value) {
    _health = value;
}

int Dragon::GetDefense() {
    return _defense;
}

void Dragon::Attack(Dragon& enemy) {
    enemy._health -= (_attack - enemy._defense);
    cout << _name << "가 " << enemy._name << "을 공격해서 생명력이 " << enemy._health << "로 줄었음." << endl;
}

void Dragon::Attack(Ogre& enemy) {
    int health = enemy.GetHealth();
    int damage = _attack - enemy.GetDefense();

    if (damage < 0) {
        damage = 0;
    }

    health -= damage;
    enemy.SetHealth(health);
    cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄었음." << endl;
}

void Dragon::Attack(Slime& enemy) {
    int health = enemy.GetHealth();
    int damage = _attack - enemy.GetDefense() - enemy.GetPhysicalRegist();

    if (damage < 0) {
        damage = 0;
    }

    health -= damage;
    enemy.SetHealth(health);
    cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄었음." << endl;
}

void Dragon::Attack(Vampire& enemy) {
    int health = enemy.GetHealth();
    int damage = _attack - enemy.GetDefense();

    if (damage < 0) {
        damage = 0;
    }

    health -= damage;
    enemy.SetHealth(health);
    cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄었음." << endl;
}

void Dragon::Info() {
    cout << "이름: " << _name << endl;
    cout << "생명력: " << _health << endl;
    cout << "공격력: " << _attack << endl;
    cout << "방어력: " << _defense << endl;
}
