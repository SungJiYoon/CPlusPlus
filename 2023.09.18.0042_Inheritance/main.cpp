#include <iostream>

using namespace std;

// ��Ӱ��迡���� �����ڿ� �Ҹ����� ȣ�� ����

class Base {
private:
    int _value;

public:
    Base() {
        cout << "Parent Ŭ���� ������" << endl;
    }

    ~Base() {
        cout << "Parent Ŭ������ �Ҹ���" << endl;
    }
};

class Derived : public Base {
private:
    int _valueDerived;

public:
    Derived() {
        cout << "Derived Ŭ���� ������" << endl;
    }

    ~Derived() {
        cout << "Derived Ŭ���� �Ҹ���" << endl;
    }

};

int main() {

    Derived derived;   // ��ü ����


    return 0;
}