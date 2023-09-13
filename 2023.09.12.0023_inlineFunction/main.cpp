#include <iostream>
#include <string>

using namespace std;

class Building {
private:
    string _name;
    float _area;
    int _maxFloor;

public:
    Building(string name, float area, int maxFloor)
        : _name(name), _area(area), _maxFloor(maxFloor) {}

    string GetName() {
        return _name;
    }

    float GetArea() {
        return _area;
    }

    int GetMaxFloor() {
        return _maxFloor;
    }

    void CheckFloor(int floor) {
        switch (floor) {
        case -1:
            cout << "���� 1�� ��� �ý����� üũ�մϴ�." << endl;
            break;

        case 1:
            cout << "1�� ���������� �ý����� üũ�մϴ�." << endl;
            break;

        case 2:
            cout << "2�� ��ȭ �ý����� üũ�մϴ�." << endl;
            break;

        default:
            cout << floor << "�� �Ϲ� �ý����� üũ�մϴ�." << endl;
            break;
        }
    }

    // ��� �Լ��� �޸� ������ ����Ǿ��ִ� / �����Լ��� �޸𸮿� �ִ�
    // ���� �Լ��� �ִ� ��ɾ CPU�� �о����
    // ���� �Լ��� ��ɾ �о�ٰ� CheckAllFloor()�� ȣ���϶�� ���� ������
    // CehckAllFloor() ������ instruction pointer�� �ٲ��
    // �Լ� ȣ���� �����̴�
    // �Լ��ȿ� ��ɾ� �� ������ �޸� ������ ������ ������ �������� ���ƿ´�
    // ���� �鸸���� ȣ���Ѵ� ���� �� �����ϰ� �ҷ����� �ϴ� �κ��� ������尡 ũ��
    // �̷��� �Լ�ȣ�⺸�ٴ� �׳� �Լ� �ȿ� �ִ� �ڵ带 �׳� �ھƹ����°� �� ���� ���� �ִ�
    // �׷��� inline �Լ��� ����Ѵ� 
    // inline �Լ��� �Լ��� �Լ��� "�����" �ȿ��ٰ� ������ �صθ� �����Ϸ��� �Լ�ȣ�⸻�� �ڵ带 �׳� �ھ��ִ� ���̴�
    void CheckAllFloor() {
        cout << endl;
        cout << "������ ��� �ý����� üũ�մϴ�." << endl;

        for (int i = 0; i < _maxFloor; i++) {
            CheckFloor(i);
        }
    }
};

// C++���� �»������� C����� ���������� ������� ������ �Ǿ����ϴ�.
// �����(.h, �������), ������(.cpp)�� ����� �����ϵ��� �Ǿ��ֽ��ϴ�.
// Ŭ���� ���ο��� �Լ��� ������ �ϴ� ���(�����ΰ� �ִ� ���) �����Ϸ���
// inline �Լ��� ����� �޶�� ��û���� �޾Ƶ帳�ϴ�.
// �ݵ�� inline�Լ��� ����� ���� ���� �ƴմϴ�.
// �����Ϸ��� �Ǵ��ؼ� inline �Լ��� ���� �� ������ inline�Լ���
// ó���ϰ� ���ϴ� ��쿡�� �Լ��� ����ϴ�.
  
int main() {
    Building starTower("��ŸŸ��", 112300.23f, 23);

    cout << "������: " << starTower.GetName() << endl;
    cout << "��ü����: " << starTower.GetArea() << endl;
    cout << "��ü����: " << starTower.GetMaxFloor() << endl;

    starTower.CheckFloor(-1);

    cout << "CheckAllFloor" << endl;

    starTower.CheckAllFloor();

    return 0;
}