#include <iostream>

using namespace std;

// 증감 연산자
// ++ , --
// 증감연산자는 정수형 변수에 사용합니다.
// 변수의 값을 1 증가 시키거나 1 감소 시킵니다.

int main() {
	int a = 20;
	int c = 0;

	++a;   // 전위식
	// a = a + 1;

	cout << "++a = " << a << endl;

	a++;   // 후위식
	// a = a + 1;
	cout << "a++ = " << a << endl;


	c = ++a;
	// a = a + 1;
	// c = a;
	cout << "c = ++a : " << "c = " << c << ", a = " << a << endl;

	c = a++;
	// c = a;
	// a = a + 1;
	cout << "c = a++ : " << "c = " << c << " , a = " << a << endl;


	--a;
	// a = a - 1;

	a--;
	// a = a - 1;



	return 0;
}