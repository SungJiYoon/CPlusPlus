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

enum DrinkType {
    COFFEE,
    LATTE,
    COLA,
    TEA
};

class Drink {
private:
    DrinkType _type;
public:
    Drink(DrinkType type)
        : _type(type)
    {}

    DrinkType GetType() {
        return _type;
    }

    string GetName() {
        return "음료";
    }

};

class Coffee : public Drink {
public:
    Coffee()
        : Drink(COFFEE)
    {}

    string GetName() {
        return "커피";
    }

};

class Latte : public Drink {
public:
    Latte()
        : Drink(LATTE)
    {}

    string GetName() {
        return "라떼";
    }

};

class Cola : public Drink {
public:
    Cola()
        : Drink(COLA)
    {}

    string GetName() {
        return "콜라";
    }

};

class Tea : public Drink {
public:
    Tea()
        : Drink(TEA)
    {}

    string GetName() {
        return "차";
    }

};

class Barista {
public:
    void MakeADrink(Drink& drink) {
        cout << drink.GetName() << "를 만듭니다." << endl;
    }
};

class Cashier {
private:
    Barista& _refBari;   // 참조(Agreggation)

public:
    Cashier(Barista& ref)
        : _refBari(ref) {}

    void OrderedDrink(Drink& drink) {
        cout << drink.GetName() << "를 주문받습니다." << endl;
        _refBari.MakeADrink(drink);
    }
};

class Guest {
public:
    void OrderingDrink(Cashier& ref, Drink& drink) { // 의존적관계(Dependency)
        cout << drink.GetName() << "를 주문합니다." << endl;
        ref.OrderedDrink(drink);
    }
};


int main() {
    Coffee coffee;
    Latte latte;
    Cola cola;
    Tea tea;

    Barista bari;
    Cashier cashier(bari);   // 바리스타와 포함(참조)
    Guest guest;


    guest.OrderingDrink(cashier, coffee);
    cout << endl;
    guest.OrderingDrink(cashier, latte);
    cout << endl;
    guest.OrderingDrink(cashier, cola);
    cout << endl;
    guest.OrderingDrink(cashier, tea);


    return 0;
}