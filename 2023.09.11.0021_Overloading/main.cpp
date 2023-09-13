#include <iostream>
#include <string>

using namespace std;

// c++ 오버로딩을 지원합니다.
// Overloading(오버로딩) : 같은 이름의 함수를 만드는 것

// C언어에서는 한프로젝트를 통털어서 같은 이름의 함수가 있을 수 없습니다.
// C++언어에서는 동일한 프로젝트에 동일한 이름의 함수가 있을 수 있습니다.
// 이것을 오버로딩이라고 합니다.
// 이름은 동일하지만 매개변수의 데이타 타입이나 매개변수의 갯수가 달라야 합니다. return type 무관.

// C++에서는 함수의 이름을 네이밍할때 네임맹글링이라는 네이밍 방법을 사용합니다.
// 함수의 이름에 매개변수의 데이타 타입이나 갯수를 포함시키는 방법입니다.



float add(float a, float b) { // addYY (네임맹글링)
	return a + b;
}

// float add(float a, float b)와 함수이름과 매개변수의 갯수와 데이타 타입이 
// 같아서 동일한 함수입니다. return type은 함수이름을 따지는 데 포함되지 않습니다.
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

	add(20, 30); // call _add; // C언어에서는 내부적으로 쓰는 함수이름에 _(언더스코어)를 붙입니다.

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