#include <iostream>

using namespace std;

// 제어문
// 프로그램의 실행 흐름을 제어할때 사용합니다.
// 제어문에는 조건문, 반복문이 있습니다.
// 조건문은 분기문으로 분류하기도 합니다.

// 조건 분기
// if, if-else, if-else-if
// switch-case (선택문)

// 무조건 분기
// goto

// 반복문
// for, while, do-while

int main() {
    int value;
    cout << "정수값을 입력하세요: ";
    cin >> value;

    if (value > 10) {   // 단일 조건문
        cout << "입력한 정수값: " << value << "가 10보다 큽니다." << endl;
    }

    if (value >= 10) {   // 이중 조건문
        cout << "입력한 정수값: " << value << "가 10보다 크거나 같습니다." << endl;
    }
    else {
        cout << "입력한 정수값: " << value << "가 10보다 작습니다." << endl;
    }


    return 0;
}