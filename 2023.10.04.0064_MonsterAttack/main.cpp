#include <iostream>
#include <string>
#include "Dragon.h"
#include "Ogre.h"
#include "Slime.h"
#include "Zombi.h"
#include "Golem.h"

using namespace std;
// ∏ÛΩ∫≈Õ

int main() {
	Dragon dragonA("dragonA", 100, 24, 10);
	Dragon dragonB("dragonB", 90, 20, 12);

	Ogre ogreA("ogreA", 50, 10, 8);
	Ogre ogreB("ogreB", 48, 11, 9);

	Slime slimeA("slimeA", 30, 5, 5, 5);
	Slime slimeB("slimeB", 28, 8, 7, 10);

	Zombi zombiA("zombiA", 50, 15, 5);
	Golem golemA("golemA", 80, 30, 10, 8);


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
	dragonA.Info();

	cout << endl;
	zombiA.Attack(ogreA);
	ogreA.Info();

	cout << endl;
	ogreA.Attack(zombiA);
	zombiA.Info();

	cout << endl;
	ogreA.Attack(golemA);
	golemA.Info();



	return 0;
}