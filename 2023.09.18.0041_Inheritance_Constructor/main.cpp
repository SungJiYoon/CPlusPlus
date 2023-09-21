#include <iostream>

using namespace std;
// c++ 언어에서는 상속관계에서 접근제어자를 사용할 수 있습니다.
// final 키워드는 상속을 막을때 사용합니다.
// class Parent final{}
class Parent {
public:
    int _value;
    int _value2;

public:
    Parent() : _value(0), _value2(0) {}

    Parent(int value, int value2)
        : _value(value), _value2(value2) {}
};

// public -> 부모의 클래스의 접근제어자 속성을 그대로 물려받음.
// protected로 하면 부모 클래스를 protected로 상속 받음.
// protected, private = protected
class Child : public Parent {
public:
    int _value3;
    int _value4;

public:
    Child() : Parent(0, 0), _value3(0), _value4(3) {}
    Child(int value, int value2, int value3, int value4)
        : Parent(value, value2), _value3(value3), _value4(value4) {}

    void Info() {
        cout << "_value = " << _value << endl;
        cout << "_value2 = " << _value2 << endl;
        cout << "_value3 = " << _value3 << endl;
        cout << "_value4 = " << _value4 << endl;
    }
};

int main() {
    Parent a(100, 200);
    Child b(10, 20, 30, 40);

    cout << "Parent 클래스" << endl;
    cout << "a._value = " << a._value << endl;
    cout << "a._value2 = " << a._value2 << endl;


    cout << endl;
    cout << "Child의 Info 멤버함수 = " << endl;

    b.Info();


    cout << endl;
    cout << "Child의 멤버변수를 바로 접근" << endl;
    cout << "b._value = " << b._value << endl;
    cout << "b._value2 = " << b._value2 << endl;
    cout << "b._value3 = " << b._value3 << endl;
    cout << "b._value4 = " << b._value4 << endl;


    return 0;
}