#include <iostream>
#include "Global.h"
#include "Test.h"

using namespace std;


int main() {

	Global global;  // global ���ڸ� ��� ������ �ؾ���. ���ŷ���.
					// �׷��� static�� �̿��ؼ� ������ �ܼ��ϰ� �������

	global.Score = 100;

	Test ts;
	Test2 ts2;
	ts.SetGlobalScore(ts2, global, 2000);


	cout << "Global::Score = " << global.Score << endl;

	ts.PrintGlobalScore(global);



	return 0;
}