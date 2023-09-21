#include <iostream>
#include <string>

using namespace std;

// 동물 육성 시뮬레이션 게임
// 특수화
// 돼지, 소, 닭

// C에서는 typedef enum tagType{}Type 했는데 C++에선 그냥 Type이라고 쓰면된다.
enum Type {   // 열거체
    COW,
    PIG,
    CHICKEN
};

class Animal {
private:
    Type _type;   // 0: 소, 1: 돼지, 2: 닭
    string _name;
    float _weight;
    float _height;
    float _healthRate;
    bool _isFly;

    void Fly() {
        cout << _name << "이 납니다." << endl;
    }

public:
    Animal(Type type, string name, float weight, float height, float healthRate, bool isFly)
        : _type(type), _name(name), _weight(weight), _height(height), _healthRate(healthRate), _isFly(isFly) {}

    void Speak() {
        switch (_type) {
        case COW:
            cout << _name << "가 음매합니다. " << endl;
            break;

        case PIG:
            cout << _name << "가 꿀꿀합니다." << endl;
            break;

        case CHICKEN:
            cout << _name << "이 꼬끼오합니다." << endl;
            break;

        default:
            cout << _name << "이 아무말도 안합니다." << endl;
            break;
        }
    }


    void Run() {
        if (_isFly) {
            Fly();
        }
        else {
            cout << _name << "가 뜁니다." << endl;
        }
    }

    void Info() {
        cout << "이름: " << _name << endl;
        cout << "몸무게: " << _weight << endl;
        cout << "신장: " << _height << endl;
        cout << "건강지수: " << _healthRate << endl;

        if (_type == CHICKEN) {
            if (_isFly) {
                cout << "종류: 나는 닭" << endl;
            }
            else {
                cout << "종류: 못 나는 닭" << endl;
            }
        }

        cout << endl;
    }

};



int main() {
    Animal pig(PIG, "돼지", 230.0f, 160.0f, 88.0f, false);
    Animal cow(COW, "소", 280.0f, 200.0f, 77.0f, false);
    Animal flyChicken(CHICKEN, "나는 닭", 4.0f, 40.0f, 90.0f, true);
    Animal notFlyChicken(CHICKEN, "못 나는 닭", 4.5f, 43.0f, 66.0f, false);

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