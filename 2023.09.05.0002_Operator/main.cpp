#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// 임의의 값을 일정한 범위의 값으로 만들때 나머지 연산자(%)를
// 사용합니다.

int main() {
    srand(time(NULL));   // 현재시간으로 난수 발생용 초기값 만듦니다.

    int value = 101;

    int ret = value % 2;   // % 나머지 연산자

    cout << ret << "= " << ret << endl;

    // 캐릭터를 만났을때
    // 0: 공격, 1: 수비, 2: 도망

    int randValue = rand();   // 난수 발생
    int actionType = randValue % 3;

    cout << "randValue = " << randValue << endl;
    cout << "actionType = " << actionType << endl;

    switch (actionType) {
    case 0:
        cout << "공격" << endl;
        break;

    case 1:
        cout << "수비" << endl;
        break;

    case 2:
        cout << "도망" << endl;
        break;
    }

    return 0;
}