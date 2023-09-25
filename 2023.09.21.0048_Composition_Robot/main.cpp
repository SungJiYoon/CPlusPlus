#include <iostream>
#include <string>

using namespace std;


class Arm {
private:
    string _name;

public:
    Arm(string name)
        : _name(name) {}

    void Info() {
        cout << _name;
    }
};

class CannonArm : public Arm {
public:
    CannonArm()
        : Arm("캐논암") {}
};

class BombArm : public Arm {
public:
    BombArm()
        : Arm("폭탄암") {}
};

class LazerArm : public Arm {
public:
    LazerArm()
        : Arm("레이저암") {}
};

class GunArm : public Arm {
public:
    GunArm()
        : Arm("건암") {}
};

// 맨처음 Arm을 참조타입으로 받았으나 좀 더 유연하게 바꾸기 위해 포인터타입으로 변경
class Robot {
private:
    string _name;
    Arm* _pLeftArm;
    Arm* _pRightArm;

public:
    Robot(string name, Arm* pLeftArm, Arm* pRightArm)
        : _name(name), _pLeftArm(pLeftArm), _pRightArm(pRightArm) {}

    void ChangeLeftArm(Arm* pLeftArm) {
        _pLeftArm = pLeftArm;
    }

    void ChangeRightArm(Arm* pRightArm) {
        _pRightArm = pRightArm;
    }


    void Info() {
        cout << " -- " << _name << " --" << endl;
        cout << "왼쪽팔: ";
        _pLeftArm->Info();
        cout << endl;
        cout << "오른쪽팔: ";
        _pRightArm->Info();
        cout << endl;
        cout << endl;
    }
};


// 상속을 과감히 버리고 포함관계를 이용
// Arm은 상속, Robot은 포함관계를 사용함
int main() {
    CannonArm cannonArm;
    BombArm bombArm;
    LazerArm lazerArm;
    GunArm gunArm;

    Robot cannonArmRobot("캐논암 로봇", &cannonArm, &cannonArm);
    Robot bombArmRobot("폭탄암 로봇", &bombArm, &bombArm);
    Robot lazerArmRobot("레이저암 로봇", &lazerArm, &lazerArm);
    Robot gunArmRobot("건암 로봇", &gunArm, &gunArm);
    Robot lCannonRLazerRobot("왼쪽캐논오른쪽레이저암로봇", &cannonArm, &lazerArm);


    cannonArmRobot.Info();
    bombArmRobot.Info();
    lazerArmRobot.Info();
    gunArmRobot.Info();
    lCannonRLazerRobot.Info();

    lCannonRLazerRobot.ChangeLeftArm(&bombArm);
    lCannonRLazerRobot.ChangeRightArm(&gunArm);
    lCannonRLazerRobot.Info();

    return 0;
}