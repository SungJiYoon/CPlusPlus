#include <iostream>
#include <string>

using namespace std;


// DataType�� �Ϲ�ȭ�� ���α׷��� ȯ���� ����.
// generic programming(�Ϲ�ȭ ���α׷���)
// C++ template

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

    Complex operator+(Complex& rightValue) {
        return Complex(_real + rightValue._real, _imaginary + rightValue._imaginary);
    }
};


ostream& operator<<(ostream& o, Complex& rightValue) {
    o << rightValue.GetReal() << showpos << rightValue.GetImaginary() << "i";
    o << noshowpos;

    return o;
}

/*
int add(int a, int b) {
   return a + b;
}

float add(float a, float b) {
   return a + b;
}

double add(double a, double b) {
   return a + b;
}

string add(string a, string b) {
   return a + b;
}

Complex add(Complex a, Complex b){
   return a + b;
}
*/

// ���ø� �Լ�(T���� ġȯ�Ǵ� �Լ��� Ʋ�� ����)
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    int a = 20;
    int b = 30;

    float c = 1.3f;
    float d = 10.4f;

    double e = 30.33;
    double f = 22.456;

    string str1 = "monster";
    string str2 = " is World!!";

    Complex aa(10, 10);
    Complex bb(12, 12);
    Complex cc(0, 0);

    cout << a << " + " << b << " = " << add(a, b) << endl;
    cout << c << " + " << d << " = " << add(c, d) << endl;
    cout << e << " + " << f << " = " << add(e, f) << endl;
    cout << str1 << " + " << str2 << " = " << add(str1, str2) << endl;

    cc = add(aa, bb);

    cout << cc;
    cout << endl;

    return 0;
}