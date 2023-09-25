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


class Robot {
private:
    string _name;
    Arm& _leftArm;
    Arm& _rightArm;

public:
    Robot(string name, Arm& leftArm, Arm& rightArm)
        : _name(name), _leftArm(leftArm), _rightArm(rightArm) {}


    void Info() {
        cout << " -- " << _name << " --" << endl;
        cout << "왼쪽팔: ";
        _leftArm.Info();
        cout << endl;
        cout << "오른쪽팔: ";
        _rightArm.Info();
        cout << endl;
        cout << endl;
    }
};

class CannonArmRobot : public Robot {
public:
    CannonArmRobot(CannonArm& leftArm, CannonArm& rightArm)
        : Robot("캐논암 로봇", leftArm, rightArm)
    {}
};

class BombArmRobot : public Robot {
public:
    BombArmRobot(BombArm& leftArm, BombArm& rightArm)
        : Robot("폭탄암 로봇", leftArm, rightArm) {}
};

class LazerArmRobot : public Robot {
public:
    LazerArmRobot(LazerArm& leftArm, LazerArm& rightArm)
        : Robot("레이저암 로봇", leftArm, rightArm)
    {}
};

class GunArmRobot : public Robot {
public:
    GunArmRobot(GunArm& leftArm, GunArm& rightArm)
        : Robot("건암 로봇", leftArm, rightArm) {}
};

class LeftCannonArmRightLazerArmRobot : public Robot {
public:
    LeftCannonArmRightLazerArmRobot(CannonArm& leftArm, LazerArm& rightArm)
        : Robot("왼쪽캐논오른쪽레이저암 로봇", leftArm, rightArm) {}
};

// 상속으로 구조를 만들었으나
// 팔을 하나 다르게 끼웠는데 과연 상속이 나은건가 처음의 포함관계가 더 낫지않은가 생각
int main() {
    CannonArm cannonArm;
    BombArm bombArm;
    LazerArm lazerArm;
    GunArm gunArm;

    CannonArmRobot cannonArmRobot(cannonArm, cannonArm);
    BombArmRobot bombArmRobot(bombArm, bombArm);
    LazerArmRobot lazerArmRobot(lazerArm, lazerArm);
    GunArmRobot gunArmRobot(gunArm, gunArm);
    LeftCannonArmRightLazerArmRobot lCannonRLazerRobot(cannonArm, lazerArm);


    cannonArmRobot.Info();
    bombArmRobot.Info();
    lazerArmRobot.Info();
    gunArmRobot.Info();
    lCannonRLazerRobot.Info();

    return 0;
}