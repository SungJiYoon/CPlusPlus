#include <iostream>

using namespace std;

// ���
// ���α׷��� ���� �帧�� �����Ҷ� ����մϴ�.
// ������� ���ǹ�, �ݺ����� �ֽ��ϴ�.
// ���ǹ��� �б⹮���� �з��ϱ⵵ �մϴ�.

// ���� �б�
// if, if-else, if-else-if
// switch-case (���ù�)

// ������ �б�
// goto

// �ݺ���
// for, while, do-while

int main() {
    int value;
    cout << "�������� �Է��ϼ���: ";
    cin >> value;

    if (value > 10) {   // ���� ���ǹ�
        cout << "�Է��� ������: " << value << "�� 10���� Ů�ϴ�." << endl;
    }

    if (value >= 10) {   // ���� ���ǹ�
        cout << "�Է��� ������: " << value << "�� 10���� ũ�ų� �����ϴ�." << endl;
    }
    else {
        cout << "�Է��� ������: " << value << "�� 10���� �۽��ϴ�." << endl;
    }


    return 0;
}