#include <iostream>
#include <string>
#include "Building.h"

using namespace std;


// C++언어는 태생적으로 C언어의 구문구조를 기반으로 개발이 되었습니다.
// 선언부(.h, 헤더파일), 구현부(.cpp)로 나누어서 개발하도록 되어있습니다.
// 클래스 내부에서 함수의 구현을 하는 경우(구현부가 있는 경우) 컴파일러는 
// 조금 다르게 받아드립니다.
// inline 함수로 만들어 달라는 요청으로 받아드립니다.
// 반드시 inline함수로 만들어 지는 것은 아닙니다.
// 컴파일러가 판단해서 inline 함수로 만들수 있으면 inline함수로
// 처리하고 못하는 경우에는 함수로 만듭니다.

int main()
{
	Building starTower("스타타워", 112300.23f, 23);

	cout << "빌딩명: " << starTower.GetName() << endl;
	cout << "전체면적: " << starTower.GetArea() << endl;
	cout << "전체층수: " << starTower.GetMaxFloor() << endl;

	starTower.CheckFloor(-1);

	cout << "CheckAllFloor" << endl;
	starTower.CheckAllFloor();

	return 0;
}