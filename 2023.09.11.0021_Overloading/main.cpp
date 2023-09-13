#include <iostream>
#include <string>

using namespace std;

// c++ �����ε��� �����մϴ�.
// Overloading(�����ε�) : ���� �̸��� �Լ��� ����� ��

// C������ ��������Ʈ�� ���о ���� �̸��� �Լ��� ���� �� �����ϴ�.
// C++������ ������ ������Ʈ�� ������ �̸��� �Լ��� ���� �� �ֽ��ϴ�.
// �̰��� �����ε��̶�� �մϴ�.
// �̸��� ���������� �Ű������� ����Ÿ Ÿ���̳� �Ű������� ������ �޶�� �մϴ�. return type ����.

// C++������ �Լ��� �̸��� ���̹��Ҷ� ���Ӹͱ۸��̶�� ���̹� ����� ����մϴ�.
// �Լ��� �̸��� �Ű������� ����Ÿ Ÿ���̳� ������ ���Խ�Ű�� ����Դϴ�.



float add(float a, float b) { // addYY (���Ӹͱ۸�)
	return a + b;
}

// float add(float a, float b)�� �Լ��̸��� �Ű������� ������ ����Ÿ Ÿ���� 
// ���Ƽ� ������ �Լ��Դϴ�. return type�� �Լ��̸��� ������ �� ���Ե��� �ʽ��ϴ�.
/*
int add(float a, float b) {
   return a + b;
}
*/

float add(float a, int b) {      // addYZ
	return a + b;
}

int add(int a, int b) { //addXX
	return a + b;
}

double add(double a, double b) {  // addZZ
	return a + b;
}

int add(int a, int b, int c) { // addXXX
	return a + b + c;
}

string add(string a, string b) {
	return a + b;
}




int main() {

	add(20, 30); // call _add; // C������ ���������� ���� �Լ��̸��� _(������ھ�)�� ���Դϴ�.

	int a = 20;
	int b = 30;

	float c = 2.4f;
	float d = 3.4f;

	double e = 10.3;
	double f = 23.4;

	string g = "Monster";
	string h = " Is World!!";

	cout << a << " + " << b << " = " << add(a, b) << endl;  // call addXX
	cout << c << " + " << d << " = " << add(c, d) << endl;  // call addYY
	cout << e << " + " << f << " = " << add(e, f) << endl;  // call addZZ
	cout << g << " + " << h << " = " << add(g, h) << endl;  // call addSS


	return 0;
}