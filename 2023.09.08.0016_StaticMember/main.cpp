#include <iostream>

using namespace std;

// 서로 연관성은 없는데 유용한거만 모아놓은 클래스
// 객체 생성하기 귀찮으니까 static 함수로 만들어서 바로바로 접근하게 만듦
class Utility {
public:
    static float add(int a, int b) {
        return a + b;
    }

    static float sub(int a, int b) {
        return a - b;
    }

    static float mul(int a, int b) {
        return a * b;
    }


    static float div(int a, int b) {
        return a / (float)b;
    }
};

int main() {
    int a = 20;
    int b = 30;

    Utility util;

    cout << a << " + " << b << " = " << util.add(a, b) << endl;
    cout << a << " - " << b << " = " << util.sub(a, b) << endl;
    cout << a << " x " << b << " = " << util.mul(a, b) << endl;
    cout << a << " / " << b << " = " << util.div(a, b) << endl;



    // 정적멤버함수로 만들어서 객체를 생성하지 않고
    // 클래스명을 통해서 바로 접근할 수가 있습니다.
    // static 남발하면 안되긴함
    cout << a << " + " << b << " = " << Utility::add(a, b) << endl;
    cout << a << " - " << b << " = " << Utility::sub(a, b) << endl;
    cout << a << " x " << b << " = " << Utility::mul(a, b) << endl;
    cout << a << " / " << b << " = " << Utility::div(a, b) << endl;



    return 0;
}