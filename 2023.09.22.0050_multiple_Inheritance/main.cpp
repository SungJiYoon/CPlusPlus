#include <iostream>
#include <string>

using namespace std;

class Lion {
private:
    string _color;

public:
    Lion(string color)
        : _color(color) {}

    void Attack() {
        cout << "사자의 앞발 공격" << endl;
    }

    string GetColor() {
        return _color;
    }
};

class Tiger {
private:
    string _color;

public:
    Tiger(string color)
        : _color(color) {}

    void Attack() {
        cout << "호랑이의 목 물기 공격" << endl;
    }

    string GetColor() {
        return _color;
    }

};

class Liger : public Lion, public Tiger {
public:
    Liger(string lionColor, string tigerColor)
        : Lion(lionColor), Tiger(tigerColor) {}

    void Attack() {
        cout << "-- Liger의 공격 --" << endl;
        Lion::Attack();
        Tiger::Attack();
        cout << " ----------------" << endl;
    }

    void ShowColor() {
        cout << "Lion의 컬러는: ";
        cout << "머리: " << Lion::GetColor() << " ";
        cout << "몸통: " << Tiger::GetColor();
        cout << endl;
    }
};

int main() {
    Liger liger("Red", "Black");

    liger.Attack();

    liger.ShowColor();
}