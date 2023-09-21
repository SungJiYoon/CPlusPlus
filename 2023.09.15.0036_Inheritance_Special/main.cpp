#include <iostream>
#include <string>

using namespace std;

// ���� ���� �ùķ��̼� ����
// Ư��ȭ
// ����, ��, ��

// C������ typedef enum tagType{}Type �ߴµ� C++���� �׳� Type�̶�� ����ȴ�.
enum Type {   // ����ü
    COW,
    PIG,
    CHICKEN
};

class Animal {
private:
    Type _type;   // 0: ��, 1: ����, 2: ��
    string _name;
    float _weight;
    float _height;
    float _healthRate;
    bool _isFly;

    void Fly() {
        cout << _name << "�� ���ϴ�." << endl;
    }

public:
    Animal(Type type, string name, float weight, float height, float healthRate, bool isFly)
        : _type(type), _name(name), _weight(weight), _height(height), _healthRate(healthRate), _isFly(isFly) {}

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
            cout << _name << "�� �ݴϴ�." << endl;
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
    Animal pig(PIG, "����", 230.0f, 160.0f, 88.0f, false);
    Animal cow(COW, "��", 280.0f, 200.0f, 77.0f, false);
    Animal flyChicken(CHICKEN, "���� ��", 4.0f, 40.0f, 90.0f, true);
    Animal notFlyChicken(CHICKEN, "�� ���� ��", 4.5f, 43.0f, 66.0f, false);

    pig.Speak();
    cow.Speak();
    flyChicken.Speak();
    notFlyChicken.Speak();

    cout << endl;
    pig.Run();
    cow.Run();
    flyChicken.Run();
    notFlyChicken.Run();

    cout << endl;
    pig.Info();
    cow.Info();
    flyChicken.Info();
    notFlyChicken.Info();


    return 0;
}