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
        : Arm("ĳ���") {}
};

class BombArm : public Arm {
public:
    BombArm()
        : Arm("��ź��") {}
};

class LazerArm : public Arm {
public:
    LazerArm()
        : Arm("��������") {}
};

class GunArm : public Arm {
public:
    GunArm()
        : Arm("�Ǿ�") {}
};

// ��ó�� Arm�� ����Ÿ������ �޾����� �� �� �����ϰ� �ٲٱ� ���� ������Ÿ������ ����
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
        cout << "������: ";
        _pLeftArm->Info();
        cout << endl;
        cout << "��������: ";
        _pRightArm->Info();
        cout << endl;
        cout << endl;
    }
};


// ����� ������ ������ ���԰��踦 �̿�
// Arm�� ���, Robot�� ���԰��踦 �����
int main() {
    CannonArm cannonArm;
    BombArm bombArm;
    LazerArm lazerArm;
    GunArm gunArm;

    Robot cannonArmRobot("ĳ��� �κ�", &cannonArm, &cannonArm);
    Robot bombArmRobot("��ź�� �κ�", &bombArm, &bombArm);
    Robot lazerArmRobot("�������� �κ�", &lazerArm, &lazerArm);
    Robot gunArmRobot("�Ǿ� �κ�", &gunArm, &gunArm);
    Robot lCannonRLazerRobot("����ĳ������ʷ������Ϸκ�", &cannonArm, &lazerArm);


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