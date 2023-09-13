#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string _modelName;
    int _wheelCount;
    float _speed;
    bool isCargo;

    // 멤버 함수는 객체에 속해있지 않다
    // 객체가 만들어질 때 메모리공간에 같이 만들어지지 않는다
    // 멤버 함수는 메모리 공간에 하나만 만들어진다
    // 그럼 멤버 함수는 자기가 호출한 객체를 어떻게 구별하는가
    // 멤버 함수를 호출할 때 해당 객체의 this pointer를 같이 전달한다
    // 그럼 그 멤버 함수는 전달 받은 this 주소값을 가지고 멤버변수에 접근한다
    // 그리고 멤버 함수는 객체를 통해서 밖에 호출이 안된다. this pointer가 전달이 돼야하니까
public:
    static const int MAXSPEED = 200;

    Car(string modelName, int wheelCount, float speed)
        : _modelName(modelName), _wheelCount(wheelCount), _speed(speed), isCargo(false) {}

    // 일반변수와 멤버변수의 이름이 충돌하는 경우
    // 멤버변수앞에 this 포인터 붙여서 멤버변수임을 정확히 하시면 됩니다.
    void SetIsCargo(bool isCargo) {
        this->isCargo = isCargo;
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

    // this : 자기참조형 포인터, 객체가 할당 받은 메모리공간의 선두번지 주소값
    // this->_modelName 에서 this->는 생략되고 있었던 것. 그냥 _modelName 와 같음
    void Info() {
        cout << "모델명: " << this->_modelName << endl;
        cout << "바퀴수: " << this->_wheelCount << endl;
        cout << "현재속도: " << this->_speed << endl;
        cout << "최대속도: " << MAXSPEED << endl << endl;
        cout << "this Pointer: " << this << endl;
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
    cout << endl;
    k5.Info();
    cout << endl;
    genesis.Info();



    return 0;
}