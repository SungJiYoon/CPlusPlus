#include <iostream>
#include <string>

#include "Dragon.h"
#include "Ogre.h"

using namespace std;
// ����

// �������Ϸ��µ� �巡�￡�� ����Ÿ� �����µ� �� ���� ����.
// ����Ŵ� �巡���� ���� ���ǵǾ��־ ������ �� ����.
// �׷��� �巡��� ����Ÿ� ���ΰ����ϰ� �Ϸ��� �и��� �ؾ���.
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