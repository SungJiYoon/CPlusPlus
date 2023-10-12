#include <iostream>

using namespace std;

class Complex {
private:
    int _real;
    int _imaginary;

public:
    Complex(int real, int imaginary)
        : _real(real), _imaginary(imaginary) {}

    // Complex 타입에 대한 + 연산자
    Complex& operator+(Complex& rightValue) {
        Complex temp(_real + rightValue._real, _imaginary + rightValue._imaginary);

        return temp;
    }

    // 뺄셈 연산자를 오버로딩 하고 뺄셈 연산을 해서 출력해보세요..
    Complex& operator-(Complex& rightValue) {
        Complex temp(_real - rightValue._real, _imaginary - rightValue._imaginary);

        return temp;
    }

    Complex& operator+(int real) {
        Complex temp(_real + real, _imaginary);

        return temp;
    }

    bool operator<(Complex& rightValue) {
        return _real < rightValue._real;
    }

    bool operator>(Complex& rightValue) {
        return _real > rightValue._real;
    }


    bool operator==(Complex& rightValue) {
        return _real == rightValue._real && _imaginary == rightValue._imaginary;
    }


    Complex& Add(Complex& value) {
        Complex temp(_real + value._real, _imaginary + value._imaginary);

        return temp;

    }

    int GetReal() {
        return _real;
    }

    int GetImaginary() {
        return _imaginary;
    }

    void Info() {
        cout << _real << showpos << _imaginary << "i";
        cout << noshowpos;
    }
};

int main() {
    Complex a(10, 10);
    Complex b(12, 12);
    Complex c(0, 0);

    a.Info();
    cout << endl;

    b.Info();
    cout << endl;

    // C++에는 사용자가 만든 데이타 타입에
    // 대한 연산기호를 사용하는 방법을 제공하고 있습니다.
    // 연산자 오버로딩(Operator overloading)
    // 객체에 연산기호를 사용하면 직관적입니다.
    // 연산자 오버로딩할때 권고 사항
    // 기존의 연산자의 연산방법에 준해서 만들어라.

    c = a + b;
    //c = a.operator+(b);

    c = a.Add(b);

    c.Info();
    cout << endl;


    c = a + 2;
    c = a.operator+(2);

    bool ret = a < b;

    c = a - b;
    c.Info();
    cout << endl;

    return 0;
}