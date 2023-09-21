#include <iostream>

using namespace std;
// c++ ������ ��Ӱ��迡�� ���������ڸ� ����� �� �ֽ��ϴ�.
// final Ű����� ����� ������ ����մϴ�.
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

// public -> �θ��� Ŭ������ ���������� �Ӽ��� �״�� ��������.
// protected�� �ϸ� �θ� Ŭ������ protected�� ��� ����.
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

    cout << "Parent Ŭ����" << endl;
    cout << "a._value = " << a._value << endl;
    cout << "a._value2 = " << a._value2 << endl;


    cout << endl;
    cout << "Child�� Info ����Լ� = " << endl;

    b.Info();


    cout << endl;
    cout << "Child�� ��������� �ٷ� ����" << endl;
    cout << "b._value = " << b._value << endl;
    cout << "b._value2 = " << b._value2 << endl;
    cout << "b._value3 = " << b._value3 << endl;
    cout << "b._value4 = " << b._value4 << endl;


    return 0;
}