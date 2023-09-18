#include <iostream>
using namespace std;

// ������
// �⺻������(���ڸ� ���� �ʴ� ������)
// ���ڸ� �޴� ������
// ���� ������ (�ڽ��� Ÿ���� ���ڷ� �޴� ������)
// �̵� ������

class Complex {
private:
    int _real;
    int _imaginary;

public:
    Complex(int real, int imaginary)
        : _real(real), _imaginary(imaginary)
    {
        cout << "Complex ���ڸ� �޴� ������" << endl;
    }

    // ���������
    // a�� b�� ���� 1��1�� �Ȱ��� ���� ���� ��������ڸ� ���� �ʿ䰡 ����.
    Complex(Complex& ref)
        : _real(ref._real), _imaginary(ref._imaginary)
    {
        cout << "Complex ���������" << endl;
    }

    ~Complex() {
        cout << "Complex �Ҹ���" << endl;
    }



    int GetReal() {
        return _real;
    }

    int GetImaginary() {
        return _imaginary;
    }

    void Info() {
        cout << _real << showpos << _imaginary << "i"; // showpos�� ���ʰ����� ��ȣ(-) ǥ�ø� ���ش�
        cout << noshowpos;                             // noshowpos�� ��ȣ ǥ�ø� ���Ѵ�. �̰� �������ָ� b���� +10-10i �̷��� ��µȴ�.
    }
};

int main() {

    Complex a(10, -10);

    cout << "a��ü" << endl;
    a.Info();
    cout << endl;

    Complex b = a;   // ��������ڰ� ȣ��˴ϴ�.
    // == Complex b(a);   // ��������ڰ� ȣ���� �˴ϴ�.

    // �Ϲ������δ� ��������ڸ� �ȸ��� �˴ϴ�.
    // �����Ϸ��� �ڵ����� ����� �ݴϴ�.

    cout << "b��ü" << endl;
    b.Info();
    cout << endl;




    return 0;
}