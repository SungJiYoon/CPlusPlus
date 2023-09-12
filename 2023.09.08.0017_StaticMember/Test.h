#pragma once
#include <iostream>
#include "Global.h"

using namespace std;
class Test {
public:

	void SetGlobalScore(int value) {
		Global::Score = value;
	}

	void PrintGlobalScore() {
		cout << "Global::Score = " << Global::Score << endl;
	}
};
