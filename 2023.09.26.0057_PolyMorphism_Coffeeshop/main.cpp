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

// 순수가상함수를 하나라도 가지고 있는 클래스를 
// 추상 클래스라고 합니다.
// 추상클래스는 자신의 객체를 만들수 있는 능력은 상실됩니다.
// 자신에게서 상속받은 자식들은 자신의 순수가상함수를 반드시 구현
// 하도록 강제하는 능력이 생깁니다.

class Drink {
public:
    Drink() {}

    virtual string GetName() = 0; // 순수가상함수 : 구현부가 없는 가상함수

    virtual void MakeADrink() = 0; // 순수가상함수
};

class Coffee : public Drink {
public:
    Coffee() {}

    string GetName() override {
        return "커피";
    }

    void MakeADrink() override {   // 부모의 가상함수를 자식이 재정의 오버라이드
        cout << "커피를 만듭니다." << endl;
    }

};

class Latte : public Drink {
public:
    Latte() {}

    string GetName() override {
        return "라떼";
    }

    void MakeADrink() override {
        cout << "라떼를 만듭니다." << endl;
    }

};

class Cola : public Drink {
public:
    Cola() {}

    string GetName() override {
        return "콜라";
    }

    void MakeADrink() override {
        cout << "콜라를 만듭니다." << endl;
    }

};

class Tea : public Drink {
public:
    Tea() {}

    string GetName() override {
        return "차";
    }

    void MakeADrink() override {
        cout << "차를 만듭니다." << endl;
    }
};

class BanillaLatte : public Drink {
public:
    BanillaLatte() {}

    string GetName() override {
        return "바닐라라떼";
    }

    void MakeADrink() override {
        cout << "바닐라라떼를 만듭니다." << endl;
    }
};

class Cidar : public Drink {
public:
    Cidar() {}

    string GetName() override {
        return "사이다";
    }

    void MakeADrink() override {
        cout << "사이다를 만듭니다." << endl;
    }
};

// Americano 클래스에 GetName(), MakeADrink() 가상함수를 
// 재정의 하지 않아도 작동상에는 문제가 없습니다.
// Drink에서 상속받은 클래스들은 반드시 GetName, MakeADrink 함수를 만들도록 강제
// 해야할 필요성이 있습니다.
class Americano : public Drink {
public:
    Americano() {}

};

class Barista {
public:
    void MakeADrink(Drink& drink) {
        cout << "음료 만드는 것을 음료에게 요청합니다. " << endl;
        drink.MakeADrink();
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

    //Drink drink; // 추상클래스의 객체는 만들수 없습니다.

    Coffee coffee;
    Latte latte;
    Cola cola;
    Tea tea;
    BanillaLatte banillalatte;
    Cidar cidar;
    //Americano americano;


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
    cout << endl;
    guest.OrderingDrink(cashier, banillalatte);
    cout << endl;
    guest.OrderingDrink(cashier, cidar);
    cout << endl;
    //guest.OrderingDrink(cashier, americano);


    return 0;
}