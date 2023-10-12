#include <iostream>

using namespace std;


class A {
private:
    int _value;
    int _value2;

public:
    A(int value, int value2)
        : _value(value), _value2(value2) {}

    void Info() {
        cout << "_value = " << _value << endl;
        cout << "_value2 = " << _value2 << endl;

    }
};

class Complex {
private:
    int _real;
    int _imaginary;

public:
    Complex(int real, int imaginary)
        : _real(real), _imaginary(imaginary) {}

    // explicit�� ������ �տ� ���� ����������ȯ ������.
    explicit Complex(int real)
        : _real(real), _imaginary(0) {}

    int GetReal() {
        return _real;
    }

    int GetImaginary() {
        return _imaginary;
    }

    // int�� ����ȯ ������
    operator int() {
        return _real;
    }

    operator A() {
        return A(_real, _imaginary);
    }

    // ���� ������ �����ε�
    Complex& operator++(int) {   // ��ġ��
        Complex temp(*this);

        _real++;
        _imaginary++;

        return temp;
    }

    Complex& operator++() {   // ��ġ��
        _real++;
        _imaginary++;

        return *this;
    }


};


int main() {
    Complex a(10, 10);
    Complex c(0, 0);

    c = a++;   // ��ġ��

    c = ++a;   // ��ġ��


    //c = 1; // ������ ����ȯ

    c = Complex(1);   // ����� ��ȯ

    int d;

    d = (int)c; // Complex Ÿ���� ���� Ÿ������ ����ȯ

    A g(0, 0);

    g = (A)c;

    return 0;
}