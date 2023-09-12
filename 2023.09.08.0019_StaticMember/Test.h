#pragma once
#include <iostream>
#include "Global.h"

using namespace std;
class Test {
public:

	void SetGlobalScore(int value) {
		Global::SetScore(value);
	}

	void PrintGlobalScore() {
		cout << "Global::Score = " << Global::GetScore() << endl;
	}
};
