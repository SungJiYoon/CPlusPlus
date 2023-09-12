#include <iostream>

using namespace std;

// ���� �������� ���µ� �����ѰŸ� ��Ƴ��� Ŭ����
// ��ü �����ϱ� �������ϱ� static �Լ��� ���� �ٷιٷ� �����ϰ� ����
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



    // ��������Լ��� ���� ��ü�� �������� �ʰ�
    // Ŭ�������� ���ؼ� �ٷ� ������ ���� �ֽ��ϴ�.
    // static �����ϸ� �ȵǱ���
    cout << a << " + " << b << " = " << Utility::add(a, b) << endl;
    cout << a << " - " << b << " = " << Utility::sub(a, b) << endl;
    cout << a << " x " << b << " = " << Utility::mul(a, b) << endl;
    cout << a << " / " << b << " = " << Utility::div(a, b) << endl;



    return 0;
}