#include <iostream>

using namespace std;

class Add {
public:
    int operator()(int a, int b) {
        return a + b;
    }

    float operator()(float a, float b) {
        return a + b;
    }
};

// ��ü�� �Լ��������� ����ϴ� ���� Functor��� �մϴ�.

int main() {

    int a = 20;
    int b = 30;

    float c = 1.2f;
    float d = 3.4f;

    Add add;

    cout << a << " + " << b << " = " << add(a, b) << endl;
    cout << a << " + " << b << " = " << add.operator()(a, b) << endl;
    cout << c << " + " << d << " = " << add(c, d) << endl;

    return 0;
}