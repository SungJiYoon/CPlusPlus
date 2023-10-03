#include <iostream>
#include <string>

#include "Dragon.h"
#include "Ogre.h"

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

    dragonA.Attack(dragonB);

    dragonB.Info();

    ogreA.Attack(ogreB);

    ogreB.Info();

    ogreB.Attack(dragonA);
    dragonA.Info();

    dragonA.Attack(ogreB);
    dragonA.Info();

    return 0;
}