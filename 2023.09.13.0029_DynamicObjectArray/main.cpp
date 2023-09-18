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


// Monster* parray = new Monster[count];
// 몬스터형 주소값을 저장하는 동적 객체 배열은 모두 delete[] 해줘야한다.
// 
// 몬스터형 주소값을 저장하는 배열의 데이터타입은 Monster**
// Monster** pparray; (몬스터 주소값을 저장하는 배열의 주소값을 저장하는 변수)
// pparray = new Monster * [count]; 은 객체 하나만 지우게 할 수 있다. 지우고 거긴 NULL값 주면 된다.
int main() {
    // 동적 객체 배열
    int count = 0;
    int index = 0;
    char buff[30];

    Monster** pparray;

    cout << "만들 몬스터의 마리수를 입력하세요: ";
    cin >> count;

    pparray = new Monster * [count];   // Monster* 을 저장하는 동적 배열을 만든다.

    for (int i = 0; i < count; i++) {
        sprintf(buff, "DynamicObjectMonster_%d", i);

        pparray[i] = new Monster(buff, i * 3, i * 4, i * 2);   // Monster* 저장하는 배열에 각각 인자를 받는 생성자를 호출해서 Monster객체를 만들고
                                                  // 객체의 주소값을 배열에 저장한다.
    }

    for (int i = 0; i < count; i++) {
        pparray[i]->Attack();   // pparray의 요소에 저장된 값은 Monster객체의 주소값입니다.
                          // 객체의 주소값으로 멤버에 접근할때는 ->(화살표연산자)를 사용합니다.
    }

    cout << endl;

    cout << "삭제하려고 하는 객체의 인덱스 번호를 입력하세요.: ";

    cin >> index;

    delete pparray[index];   // pparray Monster* 배열에 연결되어있는 index 번째 객체를 반환처리

    pparray[index] = NULL;   // Monster* 배열에 객체가 삭제된 인덱스의 저장공간에 NULL을 저장한다.

    for (int i = 0; i < count; i++) {
        if (pparray[i] != NULL)
        {
            pparray[i]->Attack();
        }   
    }

    // 객체 반환 처리
    // Monster* (몬스터형 주소값)을 저장하는 배열에 저장된 각각의 객체를 반환 처리한다.
    // NULL은 반환처리하지 않음. 이미 반환처리됐구나 하고 받아들임.
    for (int i = 0; i < count; i++) {
        delete pparray[i];
    }

    // Monster* (몬스터형 주소값)을 저장하는 동적배열을 반환 처리
    delete[] pparray;

    Monster array[10];

    return 0;
}