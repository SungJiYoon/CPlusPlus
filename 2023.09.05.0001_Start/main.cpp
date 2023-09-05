#include <iostream>

using namespace std;


int main() {
    int a = 1;
    int b = 2;

    int ret = a / b;

    cout << a << " / " << b << " = " << ret << endl;

    float fret = a / b;

    cout << a << " / " << b << " = " << fret << endl;


    fret = a / (float)b;  // 정수 / 실수
                          // 실수 / 실수 

    cout << a << " / " << b << " = " << fret << endl;
    //테스트

    return 0;
}