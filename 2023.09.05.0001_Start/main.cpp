#include <iostream>

using namespace std;


int main() {
    int a = 1;
    int b = 2;

    int ret = a / b;

    cout << a << " / " << b << " = " << ret << endl;

    float fret = a / b;

    cout << a << " / " << b << " = " << fret << endl;


    fret = a / (float)b;  // ���� / �Ǽ�
                          // �Ǽ� / �Ǽ� 

    cout << a << " / " << b << " = " << fret << endl;
    //�׽�Ʈ

    return 0;
}