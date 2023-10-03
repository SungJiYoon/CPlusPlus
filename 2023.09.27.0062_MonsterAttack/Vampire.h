#pragma once
#include <string>

class Ogre;
class Slime;
class Dragon;

class Vampire
{
private:
    std::string _name;
    int _health; 
    int _attack;  
    int _defense;  

public:
    Vampire(std::string name, int health, int attack, int defense);

    std::string GetName();

    int GetHealth();

    void SetHealth(int value);

    int GetDefense();

    void TakeHealth(int damage);

    void Attack(Vampire& enemy);
    void Attack(Dragon& enemy);
    void Attack(Ogre& enemy);
    void Attack(Slime& enemy);

    void Info();
};

