#include <iostream>

using namespace std;

class Complex {
private:
    int _real;
    int _imaginary;

public:
    Complex(int real, int imaginary)
        : _real(real), _imaginary(imaginary) {}

    // Complex Ÿ�Կ� ���� + ������
    Complex& operator+(Complex& rightValue) {
        Complex temp(_real + rightValue._real, _imaginary + rightValue._imaginary);

        return temp;
    }

    // ���� �����ڸ� �����ε� �ϰ� ���� ������ �ؼ� ����غ�����..
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

    // C++���� ����ڰ� ���� ����Ÿ Ÿ�Կ�
    // ���� �����ȣ�� ����ϴ� ����� �����ϰ� �ֽ��ϴ�.
    // ������ �����ε�(Operator overloading)
    // ��ü�� �����ȣ�� ����ϸ� �������Դϴ�.
    // ������ �����ε��Ҷ� �ǰ� ����
    // ������ �������� �������� ���ؼ� ������.

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