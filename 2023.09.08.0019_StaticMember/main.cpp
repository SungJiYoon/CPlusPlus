#include <iostream>
#include "Global.h"
#include "Test.h"

using namespace std;


int main() {

	Global::SetScore(100);

	Test ts;
	ts.SetGlobalScore(2000);


	cout << "Global::Score = " << Global::GetScore() << endl;

	ts.PrintGlobalScore();



	return 0;
}