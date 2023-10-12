#include <iostream>

using namespace std;


//Functor : 객체를 함수형식으로 사용하는 것

class Oper {
public:
    virtual float operator()(float a, float b) = 0;
    virtual int operator()(int a, int b) = 0;
    virtual int operator()(int a, int b, int c) = 0;
    virtual double operator()(double a, double b) = 0;
};


class Add : public Oper {
public:
    float operator()(float a, float b) override {
        return a + b;
    }

    int operator()(int a, int b) override {
        return a + b;
    }

    int operator()(int a, int b, int c) override {
        return a + b + c;
    }

    double operator()(double a, double b) override {
        return a + b;
    }
};

class Sub : public Oper {
public:
    float operator()(float a, float b) override {
        return a - b;
    }

    int operator()(int a, int b) override {
        return a - b;
    }

    int operator()(int a, int b, int c) override {
        return a - b - c;
    }

    double operator()(double a, double b) override {
        return a - b;
    }
};

class Mul : public Oper {
public:
    float operator()(float a, float b) override {
        return a * b;
    }

    int operator()(int a, int b) override {
        return a * b;
    }

    int operator()(int a, int b, int c) override {
        return a * b * c;
    }

    double operator()(double a, double b) override {
        return a * b;
    }
};

class Div : public  Oper {
public:
    float operator()(float a, float b) override {
        return a / b;
    }

    int operator()(int a, int b) override {
        return a / b;
    }

    int operator()(int a, int b, int c) override {
        return a / b / c;
    }

    double operator()(double a, double b) override {
        return a / b;
    }
};


int Calculator(Oper& add, int a, int b) {
    return add(a, b);
}

int Calculator(Oper& add, int a, int b, int c) {
    return add(a, b, c);
}

float Calculator(Oper& add, float a, float b)
{
    return add(a, b);
}

double Calculator(Oper& add, double a, double b) {
    return add(a, b);
}

int main() {
    int a = 20;
    int b = 30;
    int c = 40;

    float e = 3.4f;
    float f = 5.9f;

    double g = 102.123;
    double h = 34.567;

    Add add;
    Sub sub;
    Mul mul;
    Div div;


    cout << a << " + " << b << " = " << Calculator(add, a, b) << endl;
    cout << a << " + " << b << "+ " << c << " = " << Calculator(add, a, b, c) << endl;
    cout << e << " + " << f << " = " << Calculator(add, e, f) << endl;
    cout << g << " + " << h << " = " << Calculator(add, g, h) << endl;

    cout << a << " - " << b << " = " << Calculator(sub, a, b) << endl;
    cout << a << " - " << b << "+ " << c << " = " << Calculator(sub, a, b, c) << endl;
    cout << e << " - " << f << " = " << Calculator(sub, e, f) << endl;
    cout << g << " - " << h << " = " << Calculator(sub, g, h) << endl;



    return 0;
}