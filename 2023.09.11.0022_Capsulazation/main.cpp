#include <iostream>
#include <string>

using namespace std;

// 집에 있는 가전제픔 3 종류의 클래스를 각각에 만드시고
// 각각의 객체를 생성한 후에 객체의 정보를 출력해보세요...

class Television {
private:
    string _name;
    float _elecPower;
    float _attack;
    string _specialAttack;

public:
    Television(string name, float elecPower, float attack)
        : _name("TV"), _elecPower(220), _attack(100), _specialAttack("빛공격") {}

    void Attack() {
        cout << _name << "가 " << _attack << "의 힘으로 공격합니다." << endl;
        _elecPower -= _attack;
        cout << _name << "의 전기에너지가 " << _elecPower << "으로 줄었습니다." << endl;
    }

    void SpeicalAttack() {
        cout << _specialAttack << "을 합니다." << endl;
    }

    void Info() {
        cout << "이름: " << _name << endl;
        cout << "전기파워: " << _elecPower << "V" << endl;
        cout << "공격력: " << _attack << endl;
        cout << "특수공격: " << _specialAttack << endl;
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
        : _name(name), _elecPower(elecPower), _attack(attack), _temperature(temperature), _specialAttack("얼음공격")
    {

    }

    void Attack() {
        cout << _name << "이 " << _attack << "의 힘으로 공격합니다." << endl;
        _elecPower -= _attack;
        cout << _name << "의 전기에너지가 " << _elecPower << "으로 줄었습니다." << endl;

    }

    void SpeicalAttack() {
        cout << _specialAttack << "을 합니다." << endl;
    }

    void Info() {
        cout << "이름: " << _name << endl;
        cout << "전기파워: " << _elecPower << "V" << endl;
        cout << "공격력: " << _attack << endl;
        cout << "현재온도: " << _temperature << "C" << endl;
        cout << "특수공격: " << _specialAttack << endl;
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
        : _name(name), _elecPower(elecPower), _attack(attack), _innerTemperature(innerTemperature), _specialAttack("냉기공격") {}


    void Attack() {
        cout << _name << "이 " << _attack << "의 힘으로 공격합니다." << endl;
        _elecPower -= _attack;
        cout << _name << "의 전기에너지가 " << _elecPower << "으로 줄었습니다." << endl;

    }

    void SpeicalAttack() {
        cout << _specialAttack << "을 합니다." << endl;
    }

    void Info() {
        cout << "이름: " << _name << endl;
        cout << "전기파워: " << _elecPower << "V" << endl;
        cout << "공격력: " << _attack << endl;
        cout << "내부온도: " << _innerTemperature << "C" << endl;
        cout << "특수공격: " << _specialAttack << endl;
    }

};

int main() {

    Television tv("TV", 1000, 220);
    AirConditioner aircon("에어컨", 1200, 240, 23.0f);
    Refrigerator refri("냉장고", 1400, 220, -2.0f);


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