#include <iostream>
#include <string>


using namespace std;

/*
�ֹι�ȣ, ������, ����, ����, Ű, ������, ����
����ó, ����
*/

// �ֹι�ȣ(���ڿ�), ������(���ڿ�), ����(������), ����ó(���ڿ�)


// class Ŭ������ {
//  ����Ÿ;
// };
// �߻�ȭ�� ����Ÿ�� Ŭ���� Ű�����
// ���� ���� ĸ��ȭ
// ĸ��ȭ�� �ϸ� Ŭ������ ����Ÿ Ÿ���� ����̴ϴ�.
// Son �̶�� Ŭ������ ����Ÿ Ÿ���� ����̴ϴ�.
class Son {
private:
    string juminNum;   // ������� (��ü�� �Ӽ�)
    string address;
    int age;
    string phoneNum;

public:

    // ��������� �����Ҷ� Set/Get�Լ��� ����ؼ� �����ϴ� ���
    // ���������մϴ�. ����Ǵ� ���� ���Ἲ�˻�, ��ȿ���˻簡 �����մϴ�.
    void SetJumiNum(string value) { // ����Լ� (��ü�� �ൿ)
        juminNum = value;
    }

    string GetJuminNum() {
        return juminNum;
    }

    void SetAddress(string value) {
        address = value;
    }

    string GetAddress() {
        return address;
    }

    void SetAge(int value) {

        if (value < 1) {
            age = 1;
        }
        else if (value > 200) {
            age = 200;
        }
        else {
            age = value;
        }

    }

    int GetAge() {
        return age;
    }

    void SetPhoneNum(string value) {
        phoneNum = value;
    }

    string GetPhoneNum() {
        return phoneNum;
    }
};

// ĸ��ȭ�� �⺻��å�� ��������
// ���������� ĸ��ȭ�� ����Ÿ�� �ܺο� ���� �Ⱥ��� �ְڴ�(�������� �ʰڴ�.)
// ��ü������ ��ü���� ��ȣ�ۿ����� ���α׷��� �۵��ϴ� �з������ε�
// ���������� �ϸ� ��ȣ�ۿ��� �� ���� �����ϴ�.
// Ŭ�������� ����� ���� ������ �����ؾ��� �ʿ伺�� �ֽ��ϴ�.
// �̷� ��Ȱ�� �ϴ� ���� ���� �����ڶ�� �մϴ�.
// ���������ڿ���
// private // Ŭ���������� ����� ö���ϰ� ���߰ڴ�. (�⺻)
// protected // �ڽĿ��Դ� ���� ���, �ܺο����� ���� ����
// public // �ܺο� ����

// ��������� �ܺο��� �ٷ� �����ϴ� ���� ������� ����� �մϴ�.(�ǰ����)
// ����Լ��� ���ؼ� �����϶�� �մϴ�.
// ��������� �����Ҷ� ����ϴ� �Լ��� Set/Get �Լ���� �մϴ�.
// ���� �����ϴ� �Լ��� Set�Լ�
// ���� �������� �Լ��� Get�Լ�


int main() {
    Son a;

    // Ŭ������ ������ ����� �����Ҷ� .(period ������)�� ����մϴ�.
    a.SetJumiNum("111111111111");
    a.SetAddress("����");
    a.SetAge(33);
    a.SetPhoneNum("222-2222-2222");


    cout << "�ֹι�ȣ: " << a.GetJuminNum() << endl;
    cout << "�ּ�: " << a.GetAddress() << endl;
    cout << "����: " << a.GetAge() << endl;
    cout << "��ȭ��ȣ: " << a.GetPhoneNum() << endl;

    Son b;

    b.SetAge(400);



    return 0;
}