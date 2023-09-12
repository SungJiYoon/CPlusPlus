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
    static int MonsterCount;   // 정적멤버변수 , 클래스 변수

    Monster(string name, int health, int attack, int defense)
        : _name(name), _health(health), _attack(attack), _defense(defense)
    {
        cout << "Monster 생성자 호출" << endl;

        MonsterCount++;
    }

    // 소멸자는 객체가 소멸될때 자동으로 호출되어지는 멤버함수입니다.
    // 소멸자에서는 객체가 사라질때 해야하는 후단작동, 리소스해제 작업등
    ~Monster()   // 소멸자
    {
        cout << "Monster 소멸자 호출" << endl;
        MonsterCount--;
    }

    void Info() {
        cout << "몬스터명: " << _name << endl;
        cout << "생명력: " << _health << endl;
        cout << "공격력: " << _attack << endl;
        cout << "방어력: " << _defense << endl;

        cout << "몬스터 총수: " << MonsterCount << endl << endl;
    }
};

int Monster::MonsterCount = 0; // 정적멤버변수의 초기화는 클래스의 외부에서 해야합니다.


int main() {

    Monster dragon("dragon", 100, 300, 200);
    cout << "전체 몬스터의 갯수: " << Monster::MonsterCount << endl;

    {
        Monster ogre("ogre", 60, 10, 8);
        cout << "전체 몬스터의 갯수: " << Monster::MonsterCount << endl;
        {
            Monster troll("troll", 60, 15, 10);

            cout << "전체 몬스터의 갯수: " << Monster::MonsterCount << endl;
        }

        cout << "전체 몬스터의 갯수: " << Monster::MonsterCount << endl;
    }

    Monster slime("slime", 30, 20, 5);
    cout << "전체 몬스터의 갯수: " << Monster::MonsterCount << endl;

    return 0;
}