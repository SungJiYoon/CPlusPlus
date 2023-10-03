#include <iostream>

using namespace std;


struct FuncPoint {
	int(*__vfPtr[3])(int, int); // �Լ� ������ �迭
};

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}


int main() {
	int a = 20;
	int b = 30;
	FuncPoint func{ {add, sub, mul} };


	cout << a << " + " << b << " = " << func.__vfPtr[0](a, b) << endl;

	cout << a << " - " << b << " = " << func.__vfPtr[1](a, b) << endl;

	cout << a << " x " << b << " = " << func.__vfPtr[2](a, b) << endl;

	return 0;
}