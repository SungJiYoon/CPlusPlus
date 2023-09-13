#include <iostream>
#include <string>

using namespace std;

// ���� �ִ� �������� 3 ������ Ŭ������ ������ ����ð�
// ������ ��ü�� ������ �Ŀ� ��ü�� ������ ����غ�����...

class Television {
private:
    string _name;
    float _elecPower;
    float _attack;
    string _specialAttack;

public:
    Television(string name, float elecPower, float attack)
        : _name("TV"), _elecPower(220), _attack(100), _specialAttack("������") {}

    void Attack() {
        cout << _name << "�� " << _attack << "�� ������ �����մϴ�." << endl;
        _elecPower -= _attack;
        cout << _name << "�� ���⿡������ " << _elecPower << "���� �پ����ϴ�." << endl;
    }

    void SpeicalAttack() {
        cout << _specialAttack << "�� �մϴ�." << endl;
    }

    void Info() {
        cout << "�̸�: " << _name << endl;
        cout << "�����Ŀ�: " << _elecPower << "V" << endl;
        cout << "���ݷ�: " << _attack << endl;
        cout << "Ư������: " << _specialAttack << endl;
    }

};

class Refrigerator {
private:
    string _name;
    float _elecPower;
    float _attack;
    float _temperature;
    string _specialAttack;

public:
    Refrigerator(string name, float elecPower, float attack, float temperature)
        : _name(name), _elecPower(elecPower), _attack(attack), _temperature(temperature), _specialAttack("��������")
    {

    }

    void Attack() {
        cout << _name << "�� " << _attack << "�� ������ �����մϴ�." << endl;
        _elecPower -= _attack;
        cout << _name << "�� ���⿡������ " << _elecPower << "���� �پ����ϴ�." << endl;

    }

    void SpeicalAttack() {
        cout << _specialAttack << "�� �մϴ�." << endl;
    }

    void Info() {
        cout << "�̸�: " << _name << endl;
        cout << "�����Ŀ�: " << _elecPower << "V" << endl;
        cout << "���ݷ�: " << _attack << endl;
        cout << "����µ�: " << _temperature << "C" << endl;
        cout << "Ư������: " << _specialAttack << endl;
    }


};

class AirConditioner {
private:
    string _name;
    float _elecPower;
    float _attack;
    float _innerTemperature;
    string _specialAttack;

public:
    AirConditioner(string name, float elecPower, float attack, float innerTemperature)
        : _name(name), _elecPower(elecPower), _attack(attack), _innerTemperature(innerTemperature), _specialAttack("�ñ����") {}


    void Attack() {
        cout << _name << "�� " << _attack << "�� ������ �����մϴ�." << endl;
        _elecPower -= _attack;
        cout << _name << "�� ���⿡������ " << _elecPower << "���� �پ����ϴ�." << endl;

    }

    void SpeicalAttack() {
        cout << _specialAttack << "�� �մϴ�." << endl;
    }

    void Info() {
        cout << "�̸�: " << _name << endl;
        cout << "�����Ŀ�: " << _elecPower << "V" << endl;
        cout << "���ݷ�: " << _attack << endl;
        cout << "���οµ�: " << _innerTemperature << "C" << endl;
        cout << "Ư������: " << _specialAttack << endl;
    }

};

int main() {

    Television tv("TV", 1000, 220);
    AirConditioner aircon("������", 1200, 240, 23.0f);
    Refrigerator refri("�����", 1400, 220, -2.0f);


    tv.Attack();
    cout << endl;
    aircon.Attack();
    cout << endl;
    refri.Attack();
    cout << endl;

    refri.SpeicalAttack();
    cout << endl;

    tv.Info();
    cout << endl;
    aircon.Info();
    cout << endl;
    refri.Info();
    cout << endl;

    return 0;
}