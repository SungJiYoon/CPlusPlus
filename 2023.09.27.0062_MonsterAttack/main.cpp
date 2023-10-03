#include <iostream>
#include <string>

#include "Dragon.h"
#include "Ogre.h"
#include "Slime.h"
#include "Vampire.h"

using namespace std;
// 몬스터

// 컴파일하려는데 드래곤에서 오우거를 만났는데 알 수가 없음.
// 오우거는 드래곤이 먼저 정의되어있어서 공격할 수 있음.
// 그래서 드래곤과 오우거를 서로공격하게 하려면 분리를 해야함.
int main() {
    Dragon dragonA("dragonA", 100, 24, 10);
    Dragon dragonB("dragonB", 90, 20, 12);

    Ogre ogreA("ogreA", 50, 10, 8);
    Ogre ogreB("ogreB", 48, 11, 9);

    Slime slimeA("slimeA", 30, 5, 5, 5);
    Slime slimeB("slimeB", 28, 8, 7, 10);

    Vampire vampireA("vampireA", 60, 12, 7);
    Vampire vampireB("vampireB", 55, 10, 5);

    dragonA.Attack(dragonB);
    dragonB.Info();

    cout << endl;
    dragonB.Attack(slimeA);
    slimeA.Info();

    cout << endl;
    ogreA.Attack(ogreB);
    ogreB.Info();

    cout << endl;
    ogreB.Attack(dragonA);
    dragonA.Info();

    cout << endl;
    dragonA.Attack(ogreB);
    ogreB.Info();

    cout << endl;
    vampireA.Attack(dragonA);
    dragonA.Info();

    return 0;
}