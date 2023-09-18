#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Monster {
private:
    string _name;
    int _health;
    int _attack;
    int _defense;

public:
    Monster(string name, int health, int attack, int defense)
        : _name(name), _health(health), _attack(attack), _defense(defense)
    {
        cout << _name << "생성자" << endl;
    }

    ~Monster() {
        cout << _name << "소멸자" << endl;
    }

    void Attack() {
        cout << _name << "이 공격한다." << endl;
    }

    void Defense() {
        cout << _name << "이 방어한다." << endl;
    }

    void Info() {
        cout << "몬스터명: " << _name << endl;
        cout << "생명력: " << _health << endl;
        cout << "공격력: " << _attack << endl;
        cout << "방어력: " << _defense << endl;
    }

};

int main() {
    // 동적으로 객체를 생성할때는 new 연산자를 사용해야 합니다.
    // 객체가 생성될때 생성자가 호출되어야지만 온전한 객체로 생성할
    // 수 있습니다.

    // malloc을 사용해서 객체를 생성
    // malloc으로 동적객체를 만들면 안됩니다.
    // malloc은 생성자를 호출하지 않습니다.
    // free는 소멸자를 호출하지 않습니다.
    // malloc을 사용해서는 온전한 객체로 생성할 수가 없습니다.
    cout << "c의 malloc 함수를 사용" << endl;
    Monster* cpmons = (Monster*)malloc(sizeof(Monster));
    free(cpmons);


    cout << "new 연산자 사용" << endl;
    // new 연산자를 사용해서 객체를 생성
    // 객체를 생성할때는 new 연산자를 사용해야 합니다.
    // new 연산자는 생성자 호출 시키고
    // delete 연산자는 소멸자를 호출 시켜 줍니다.
    Monster* pmons = new Monster("드래곤", 100, 30, 20);   // 생성자 호출
    pmons->Attack(); // 주소값을 사용하니까 -> 써야함
    cout << endl;
    pmons->Defense();
    cout << endl;
    pmons->Info();

    delete pmons;   // 소멸자가 호출


    return 0;
}