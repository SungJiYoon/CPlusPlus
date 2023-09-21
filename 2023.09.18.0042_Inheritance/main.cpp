#include <iostream>

using namespace std;

// 상속관계에서의 생성자와 소멸자의 호출 순서

class Base {
private:
    int _value;

public:
    Base() {
        cout << "Parent 클래스 생성자" << endl;
    }

    ~Base() {
        cout << "Parent 클래스의 소멸자" << endl;
    }
};

class Derived : public Base {
private:
    int _valueDerived;

public:
    Derived() {
        cout << "Derived 클래스 생성자" << endl;
    }

    ~Derived() {
        cout << "Derived 클래스 소멸자" << endl;
    }

};

int main() {

    Derived derived;   // 객체 생성


    return 0;
}