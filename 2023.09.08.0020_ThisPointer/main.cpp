#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string _modelName;
    int _wheelCount;
    float _speed;
    bool isCargo;

public:
    static const int MAXSPEED = 200;

    Car(string modelName, int wheelCount, float speed)
        : _modelName(modelName), _wheelCount(wheelCount), _speed(speed), isCargo(false) {}

    void SetIsCargo(bool isCargo) {
        isCargo = isCargo;
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

    void Info() {
        cout << "�𵨸�: " << _modelName << endl;
        cout << "������: " << _wheelCount << endl;
        cout << "����ӵ�: " << _speed << endl;
        cout << "�ִ�ӵ�: " << MAXSPEED << endl << endl;
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
    genesis.Info();


    return 0;
}