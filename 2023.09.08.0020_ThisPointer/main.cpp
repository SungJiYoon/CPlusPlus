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
            cout << _modelName << "의 속도가 최대속도 입니다.\n" << endl;
            _speed = MAXSPEED;
        }
        else {
            cout << _modelName << "의 속도를 10올려서 현재속도가" << _speed << "입니다." << endl;
        }
    }

    void Break() {
        _speed -= 10;

        if (_speed <= 0) {
            cout << _modelName << "이 정지하였습니다." << endl;
        }
        else {
            cout << _modelName << "의 속도를 10 내려서 현재속도가 " << _speed << "입니다." << endl;
        }
    }

    void Info() {
        cout << "모델명: " << _modelName << endl;
        cout << "바퀴수: " << _wheelCount << endl;
        cout << "현재속도: " << _speed << endl;
        cout << "최대속도: " << MAXSPEED << endl << endl;
    }
};

int main() {
    Car cona("코나", 4, 100);
    Car k5("K5", 4, 180);
    Car genesis("제네시스", 4, 190);

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