#pragma once
#include <string>

class Dragon;

class Ogre {
private:
    std::string _name;
    int _health;
    int _attack;
    int _defense;

public:
    Ogre(std::string name, int health, int attack, int defense);

    std::string GetName();

    int GetHealth();

    void SetHealth(int value);

    int GetDefense();

    void Attack(Ogre& enemy);

    void Attack(Dragon& enemy);

    void Info();
};
