#include <iostream>
#include <string>

using namespace std;


// DataType에 일반화한 프로그래밍 환경을 제공.
// generic programming(일반화 프로그래밍)
// C++ template

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

// 템플릿 함수(T형에 치환되는 함수의 틀을 제공)
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