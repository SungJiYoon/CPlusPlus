#pragma once
#include "Global.h"

class Test2 {
public:

	void SetGlobalScore(Global & ref, int value) {
		ref.Score = value;
	}

};