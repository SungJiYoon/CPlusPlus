#include <iostream>
using namespace std;

// 생성자
// 기본생성자(인자를 받지 않는 생성자)
// 인자를 받는 생성자
// 복사 생성자 (자신의 타입을 인자로 받는 생성자)
// 이동 생성자

class Complex {
private:
    int _real;
    int _imaginary;

public:
    Complex(int real, int imaginary)
        : _real(real), _imaginary(imaginary)
    {
        cout << "Complex 인자를 받는 생성자" << endl;
    }

    // 복사생성자
    // a와 b가 값이 1대1로 똑같은 경우는 굳이 복사생성자를 만들 필요가 없다.
    Complex(Complex& ref)
        : _real(ref._real), _imaginary(ref._imaginary)
    {
        cout << "Complex 복사생성자" << endl;
    }

    ~Complex() {
        cout << "Complex 소멸자" << endl;
    }



    int GetReal() {
        return _real;
    }

    int GetImaginary() {
        return _imaginary;
    }

    void Info() {
        cout << _real << showpos << _imaginary << "i"; // showpos의 뒤쪽값부터 기호(-) 표시를 해준다
        cout << noshowpos;                             // noshowpos는 기호 표시를 안한다. 이거 안적어주면 b에서 +10-10i 이렇게 출력된다.
    }
};

int main() {

    Complex a(10, -10);

    cout << "a객체" << endl;
    a.Info();
    cout << endl;

    Complex b = a;   // 복사생성자가 호출됩니다.
    // == Complex b(a);   // 복사생성자가 호출이 됩니다.

    // 일반적으로는 복사생성자를 안만들어도 됩니다.
    // 컴파일러가 자동으로 만들어 줍니다.

    cout << "b객체" << endl;
    b.Info();
    cout << endl;




    return 0;
}