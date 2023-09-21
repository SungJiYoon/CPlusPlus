#include <iostream>
#include <string>

using namespace std;

// ���� ���� �ùķ��̼� ����
// Ư��ȭ
// ����, ��, ��

enum Type {   // ����ü
    COW,
    PIG,
    CHICKEN,
    DOLPHIN
};

class Animal {
private:
    Type _type;   // 0: ��, 1: ����, 2: ��, 3: ����
    string _name;
    float _weight;
    float _height;
    float _healthRate;
    bool _isFly;
    bool _isSwim;

    void Fly() {
        cout << _name << "�� ���ϴ�." << endl;
    }

    void Swim() {
        cout << _name << "�� ����� Ĩ�ϴ�." << endl;
    }

public:
    Animal(Type type, string name, float weight, float height, float healthRate, bool isFly, bool isSwim)
        : _type(type), _name(name), _weight(weight), _height(height), _healthRate(healthRate), _isFly(isFly), _isSwim(isSwim) {}

    void Speak() {
        switch (_type) {
        case COW:
            cout << _name << "�� �����մϴ�. " << endl;
            break;

        case PIG:
            cout << _name << "�� �ܲ��մϴ�." << endl;
            break;

        case CHICKEN:
            cout << _name << "�� �������մϴ�." << endl;
            break;

        case DOLPHIN:
            cout << _name << "�� �����մϴ�." << endl;
            break;

        default:
            cout << _name << "�� �ƹ����� ���մϴ�." << endl;
            break;
        }
    }


    void Run() {
        if (_isFly) {
            Fly();
        }
        else {
            if (_isSwim) {
                Swim();
            }
            else {
                cout << _name << "�� �ݴϴ�." << endl;
            }

        }
    }

    void Info() {
        cout << "�̸�: " << _name << endl;
        cout << "������: " << _weight << endl;
        cout << "����: " << _height << endl;
        cout << "�ǰ�����: " << _healthRate << endl;

        if (_type == CHICKEN) {
            if (_isFly) {
                cout << "����: ���� ��" << endl;
            }
            else {
                cout << "����: �� ���� ��" << endl;
            }
        }

        cout << endl;
    }

};



int main() {
    Animal pig(PIG, "����", 230.0f, 160.0f, 88.0f, false, false);
    Animal cow(COW, "��", 280.0f, 200.0f, 77.0f, false, false);
    Animal flyChicken(CHICKEN, "���� ��", 4.0f, 40.0f, 90.0f, true, false);
    Animal notFlyChicken(CHICKEN, "�� ���� ��", 4.5f, 43.0f, 66.0f, false, false);
    Animal dolphin(DOLPHIN, "����", 300.0f, 200.0f, 84.0f, false, true);

    pig.Speak();
    cow.Speak();
    flyChicken.Speak();
    notFlyChicken.Speak();
    dolphin.Speak();

    cout << endl;
    pig.Run();
    cow.Run();
    flyChicken.Run();
    notFlyChicken.Run();
    dolphin.Run();

    cout << endl;
    pig.Info();
    cow.Info();
    flyChicken.Info();
    notFlyChicken.Info();
    dolphin.Info();


    return 0;
}