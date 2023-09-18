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
    // 기본 생성자를 호출해서 객체 배열을 만들어야 합니다.
    Monster()
        : _name(""), _health(0), _attack(0), _defense(0)
    {
        cout << "Monster 기본생성자" << endl;
    }

    // 인자를 받는 생성자만 있는 경우엔 객체 배열을 만들 수 없다.
    // 인자를 받는 생성자를 호출해서 객체 배열을 만들 수 없다.
    Monster(string name, int health, int attack, int defense)
        : _name(name), _health(health), _attack(attack), _defense(defense)
    {
        cout << "Monster 생성자" << endl;
    }

    ~Monster() {
        cout << "Monster 소멸자" << endl;
    }

    void Init(string name, int health, int attack, int defense) {
        _name = name;
        _health = health;
        _attack = attack;
        _defense = defense;
    }

    void Attack() {
        cout << _name << "이 공격한다." << endl;
    }

    void Defense() {
        cout << _name << "이 방어한다.";
    }

    void Info() {
        cout << "몬스터명: " << _name << endl;
        cout << "생명력: " << _health << endl;
        cout << "공격력: " << _attack << endl;
        cout << "방어력: " << _defense << endl;
    }
};

int main() {
    // 객체 배열
    char buff[100];

    // 정적으로 만들었음, 동적으로 만들 수 있음
    Monster array[10];   // 객체 배열을 만들려면 기본생성자가 반드시 필요합니다.
                    

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