#include <iostream>

using namespace std;

int main() {
	// a + b 에서 +는 연산자(Operator), a와 b는 피연산자(Operand)이자 논리값이다.
	cout << "논리 And(&&) 연산자\n"; // 그리고의 의미가 있습니다.
	// 논리 And연산자는 false 확률이 높은 것을 앞쪽에 놓는 것이 유리합니다.
	bool ret = true && true;
	cout << "true && true = " << ret << endl;

	ret = true && false;
	cout << "true && false = " << ret << endl;

	ret = false && true;
	cout << "false && true = " << ret << endl;

	ret = false && false;
	cout << "false && false = " << ret << endl;

	cout << endl;
	cout << "논리 Or(||) 연산자\n" << endl; // 또는 혹은의 의미가 있습니다.
	// 논리 Or 연산자는 true확률이 높은 것을 앞쪽에 놓는 것이 유리합니다.
	ret = true || true;
	cout << "true || true = " << ret << endl;

	ret = true || false;
	cout << "true || false = " << ret << endl;

	ret = false || true;
	cout << "false || true = " << ret << endl;

	ret = false || false;
	cout << "false || false = " << ret << endl;

	cout << endl;
	cout << "논리 not(!)연산자\n" << endl;
	ret = !true;
	cout << "!true = " << ret << endl;

	ret = !false;
	cout << "!false = " << ret << endl;




	return 0;
}