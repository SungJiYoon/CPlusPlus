#include <iostream>

using namespace std;

// 관계연산자
// <, >, <= , >= , == , !=

int main() {

	int value1 = 0;
	int value2 = 0;

	cout << "처음값을 입력하세요: ";
	cin >> value1;   // cin객체는 키보드에서 값을 입력받을때 사용
	cout << "두번째 값을 입력하세요: ";
	cin >> value2;

	// 관계연산자의 연산의 결과값을 데이타 타입 : 논리값.
	bool ret = value1 > value2;

	cout << value1 << " > " << value2 << " = " << ret << endl;

	ret = value1 < value2;

	cout << value1 << " < " << value2 << " = " << ret << endl;

	ret = value1 <= value2;
	cout << value1 << " <= " << value2 << " = " << ret << endl;

	ret = value1 >= value2;
	cout << value1 << " >= " << value2 << " = " << ret << endl;

	ret = value1 == value2;
	cout << value1 << " == " << value2 << " = " << ret << endl;

	ret = value1 != value2;
	cout << value1 << " != " << value2 << " = " << ret << endl;


	return 0;
}