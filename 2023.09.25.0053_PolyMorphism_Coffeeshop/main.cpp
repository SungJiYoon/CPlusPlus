#include <iostream>
#include <string>

using namespace std;

// 다형성

// 여러분들이 프로그래머가 되어서 
// 커피숖 관리프로그램을 개발 의뢰받았습니다.
// 커피숖에 가야죠. 커피를 한잔 시키고 자리 앉아서
// 커피숖의 업무 흐름을 파악해야 하빈다.
// 커피숖에는 어떤 역활(Role)과 어떤 책임(responsibility)이 있나요.

// 역활?
// 바리스타, 매니저, 알바생, 사장님, 캐시어, 손님.


// Barista, Cashier, guest

class Coffee {
private:
    string _name;

public:
    Coffee()
        : _name("커피") {}

    string GetName() {
        return _name;
    }
};

class Latte {
private:
    string _name;

public:
    Latte()
        : _name("라떼") {}

    string GetName() {
        return _name;
    }
};

class Barista {
public:
    // 오버로딩
    // 음료가 추가되더라도 다른데는 추가 안됐음 좋겠음, 음료만 추가됐음 좋겠음. 계속 멤버함수를 만들어야하는 불편
    void MakeADrink(Coffee& drink) {
        cout << drink.GetName() << "를 만듭니다." << endl;
    }

    void MakeADrink(Latte& drink) {
        cout << drink.GetName() << "를 만듭니다." << endl;
    }
};

class Cashier {
private:
    Barista& _refBari;   // 참조(Agreggation)

public:
    Cashier(Barista& ref)
        : _refBari(ref) {}

    void OrderedDrink(Coffee& drink) {
        cout << drink.GetName() << "를 주문받습니다." << endl;
        _refBari.MakeADrink(drink);
    }

    void OrderedDrink(Latte& drink) {
        cout << drink.GetName() << "를 주문 받습니다." << endl;
        _refBari.MakeADrink(drink);
    }
};

class Guest {
public:
    void OrderingDrink(Cashier& ref, Coffee& drink) { // 의존적관계(Dependency)
        cout << drink.GetName() << "를 주문합니다." << endl;
        ref.OrderedDrink(drink);
    }

    void OrderingDrink(Cashier& ref, Latte& drink) {
        cout << drink.GetName() << "를 주문 합니다." << endl;
        ref.OrderedDrink(drink);
    }
};


int main() {
    Coffee coffee;
    Latte latte;

    Barista bari;
    Cashier cashier(bari);   // 바리스타와 포함(참조)
    Guest guest;

    guest.OrderingDrink(cashier, coffee);
    cout << endl;
    guest.OrderingDrink(cashier, latte);


    return 0;
}