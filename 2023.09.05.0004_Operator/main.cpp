#include <iostream>

using namespace std;

int main() {
	// a + b ���� +�� ������(Operator), a�� b�� �ǿ�����(Operand)���� �����̴�.
	cout << "�� And(&&) ������\n"; // �׸����� �ǹ̰� �ֽ��ϴ�.
	// �� And�����ڴ� false Ȯ���� ���� ���� ���ʿ� ���� ���� �����մϴ�.
	bool ret = true && true;
	cout << "true && true = " << ret << endl;

	ret = true && false;
	cout << "true && false = " << ret << endl;

	ret = false && true;
	cout << "false && true = " << ret << endl;

	ret = false && false;
	cout << "false && false = " << ret << endl;

	cout << endl;
	cout << "�� Or(||) ������\n" << endl; // �Ǵ� Ȥ���� �ǹ̰� �ֽ��ϴ�.
	// �� Or �����ڴ� trueȮ���� ���� ���� ���ʿ� ���� ���� �����մϴ�.
	ret = true || true;
	cout << "true || true = " << ret << endl;

	ret = true || false;
	cout << "true || false = " << ret << endl;

	ret = false || true;
	cout << "false || true = " << ret << endl;

	ret = false || false;
	cout << "false || false = " << ret << endl;

	cout << endl;
	cout << "�� not(!)������\n" << endl;
	ret = !true;
	cout << "!true = " << ret << endl;

	ret = !false;
	cout << "!false = " << ret << endl;




	return 0;
}