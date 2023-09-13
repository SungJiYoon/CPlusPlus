#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string _modelName;
    int _wheelCount;
    float _speed;
    bool isCargo;

    // ��� �Լ��� ��ü�� �������� �ʴ�
    // ��ü�� ������� �� �޸𸮰����� ���� ��������� �ʴ´�
    // ��� �Լ��� �޸� ������ �ϳ��� ���������
    // �׷� ��� �Լ��� �ڱⰡ ȣ���� ��ü�� ��� �����ϴ°�
    // ��� �Լ��� ȣ���� �� �ش� ��ü�� this pointer�� ���� �����Ѵ�
    // �׷� �� ��� �Լ��� ���� ���� this �ּҰ��� ������ ��������� �����Ѵ�
    // �׸��� ��� �Լ��� ��ü�� ���ؼ� �ۿ� ȣ���� �ȵȴ�. this pointer�� ������ �ž��ϴϱ�
public:
    static const int MAXSPEED = 200;

    Car(string modelName, int wheelCount, float speed)
        : _modelName(modelName), _wheelCount(wheelCount), _speed(speed), isCargo(false) {}

    // �Ϲݺ����� ��������� �̸��� �浹�ϴ� ���
    // ��������տ� this ������ �ٿ��� ����������� ��Ȯ�� �Ͻø� �˴ϴ�.
    void SetIsCargo(bool isCargo) {
        this->isCargo = isCargo;
    }

    void Acceleration() {
        _speed += 10;

        if (_speed > MAXSPEED) {
            cout << _modelName << "�� �ӵ��� �ִ�ӵ� �Դϴ�.\n" << endl;
            _speed = MAXSPEED;
        }
        else {
            cout << _modelName << "�� �ӵ��� 10�÷��� ����ӵ���" << _speed << "�Դϴ�." << endl;
        }
    }

    void Break() {
        _speed -= 10;

        if (_speed <= 0) {
            cout << _modelName << "�� �����Ͽ����ϴ�." << endl;
        }
        else {
            cout << _modelName << "�� �ӵ��� 10 ������ ����ӵ��� " << _speed << "�Դϴ�." << endl;
        }
    }

    // this : �ڱ������� ������, ��ü�� �Ҵ� ���� �޸𸮰����� ���ι��� �ּҰ�
    // this->_modelName ���� this->�� �����ǰ� �־��� ��. �׳� _modelName �� ����
    void Info() {
        cout << "�𵨸�: " << this->_modelName << endl;
        cout << "������: " << this->_wheelCount << endl;
        cout << "����ӵ�: " << this->_speed << endl;
        cout << "�ִ�ӵ�: " << MAXSPEED << endl << endl;
        cout << "this Pointer: " << this << endl;
    }
};

int main() {
    Car cona("�ڳ�", 4, 100);
    Car k5("K5", 4, 180);
    Car genesis("���׽ý�", 4, 190);

    cout << endl;
    cona.Acceleration();
    k5.Acceleration();
    genesis.Acceleration();

    cout << endl;
    k5.Break();

    cout << endl;
    cona.Info();
    cout << endl;
    k5.Info();
    cout << endl;
    genesis.Info();



    return 0;
}