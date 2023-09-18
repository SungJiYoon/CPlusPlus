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
        cout << "----------------------------" << endl;
        cout << "몬스터명: " << _name << endl;
        cout << "생명력: " << _health << endl;
        cout << "공격력: " << _attack << endl;
        cout << "방어력: " << _defense << endl;
        cout << "----------------------------" << endl << endl;
    }
};


int main() {
    // 동적 객체 배열
    int count = 0;
    char buff[30];

    cout << "만들 몬스터의 마리수를 입력하세요: ";
    cin >> count;

    Monster* parray = new Monster[count];   // 동적 객체 배열을 생성

    for (int i = 0; i < count; i++) {
        sprintf(buff, "DynamicMonster_%d", i);
        parray[i].Init(buff, i * 10, i * 4, i * 3);
    }

    for (int i = 0; i < count; i++) {
        parray[i].Info();
    }

    delete[] parray;   // 동적 객체배열 반환처리 

    int* pint = new int;

    delete pint;


    return 0;
}