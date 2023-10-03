#include <iostream>
#include <string>

#include "Dragon.h"
#include "Ogre.h"
#include "Slime.h"
#include "Vampire.h"

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