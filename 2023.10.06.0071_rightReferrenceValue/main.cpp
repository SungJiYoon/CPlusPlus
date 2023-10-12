#include <iostream>

using namespace std;

int main() {
	int value;

	// 값.

	value = 100 + 200;


	// 우측값 참조
	int&& rrefa = 100;


	int&& rrefb = 200;

	cout << "refa = " << rrefa << endl;
	cout << "refb = " << rrefb << endl;

	rrefa = 2000;

	cout << "rrefa = " << rrefa << endl;



	return 0;
}