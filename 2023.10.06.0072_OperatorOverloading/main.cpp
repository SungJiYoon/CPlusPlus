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

    // explicit을 생성자 앞에 쓰면 묵시적형변환 하지마.
    explicit Complex(int real)
        : _real(real), _imaginary(0) {}

    int GetReal() {
        return _real;
    }

    int GetImaginary() {
        return _imaginary;
    }

    // int형 형변환 연산자
    operator int() {
        return _real;
    }

    operator A() {
        return A(_real, _imaginary);
    }

    // 증감 연산자 오버로딩
    Complex& operator++(int) {   // 후치형
        Complex temp(*this);

        _real++;
        _imaginary++;

        return temp;
    }

    Complex& operator++() {   // 전치형
        _real++;
        _imaginary++;

        return *this;
    }


};


int main() {
    Complex a(10, 10);
    Complex c(0, 0);

    c = a++;   // 후치형

    c = ++a;   // 전치형


    //c = 1; // 묵시적 형변환

    c = Complex(1);   // 명시적 변환

    int d;

    d = (int)c; // Complex 타입을 정수 타입으로 형변환

    A g(0, 0);

    g = (A)c;

    return 0;
}