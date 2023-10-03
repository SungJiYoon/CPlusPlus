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
    cout << _name << "가 " << damage << "의 생명력을 얻음 " << endl;
    cout << "---공격 전 Info()---" << endl;
    Info();  
    cout << "---공격 후 Info()---" << endl;
    _health += damage;
    Info();
}

void Vampire::Attack(Vampire& enemy) {
    int damage = _attack - enemy._defense;
    enemy._health -= damage;
    cout << _name << "가 " << enemy._name << "을 공격해서 생명력이 " << enemy._health << "로 줄었음." << endl;
    
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
    cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄었음." << endl;
    
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
    cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄었음." << endl;

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
    cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemy.GetHealth() << "로 줄었음." << endl;

    TakeHealth(damage);
}

void Vampire::Info() {
    cout << "이름: " << _name << endl;
    cout << "생명력: " << _health << endl;
    cout << "공격력: " << _attack << endl;
    cout << "방어력: " << _defense << endl;
}