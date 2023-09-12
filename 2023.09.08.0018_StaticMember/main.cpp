#include <iostream>
#include "Global.h"
#include "Test.h"

using namespace std;


int main() {

	Global global;  // global 인자를 계속 전달을 해야함. 번거러움.
					// 그래서 static을 이용해서 구조를 단순하게 만든거임

	global.Score = 100;

	Test ts;
	Test2 ts2;
	ts.SetGlobalScore(ts2, global, 2000);


	cout << "Global::Score = " << global.Score << endl;

	ts.PrintGlobalScore(global);



	return 0;
}