#pragma once
#include <iostream>
#include "Global.h"
#include "Test2.h"

using namespace std;
class Test {
public:

	void SetGlobalScore(Test2& ref2, Global& ref, int value) {
		ref.Score = value;
		ref2.SetGlobalScore(ref, value);
	}

	void PrintGlobalScore(Global& ref) {
		cout << "Global::Score = " << ref.Score << endl;
	}
};
