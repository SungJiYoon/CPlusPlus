#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// ������ ���� ������ ������ ������ ���鶧 ������ ������(%)��
// ����մϴ�.

int main() {
    srand(time(NULL));   // ����ð����� ���� �߻��� �ʱⰪ ����ϴ�.

    int value = 101;

    int ret = value % 2;   // % ������ ������

    cout << ret << "= " << ret << endl;

    // ĳ���͸� ��������
    // 0: ����, 1: ����, 2: ����

    int randValue = rand();   // ���� �߻�
    int actionType = randValue % 3;

    cout << "randValue = " << randValue << endl;
    cout << "actionType = " << actionType << endl;

    switch (actionType) {
    case 0:
        cout << "����" << endl;
        break;

    case 1:
        cout << "����" << endl;
        break;

    case 2:
        cout << "����" << endl;
        break;
    }

    return 0;
}