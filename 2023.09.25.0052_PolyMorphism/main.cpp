#include <iostream>

using namespace std;

// 다형성
// A객체가 B객체에게 메세지를 보낼 때(A객체가 B객체안의 멤버함수를 호출한다)
// 동일한 메세지에 다양한 반응을 보이는 것

// 오버로딩   : 같은 이름의 함수를 만드는 것. 단, 매개변수의 타입이나 갯수가 틀려야한다.
// 오버라이드 : 상속관계에서 부모의 멤버함수를 자식이 재정의하는 것/ 부모의 가상함수를 자식이 재정의하는 경우


// 여러분들이 프로그래머가 되어서 
// 커피숖 관리프로그램을 개발 의뢰받았습니다.
// 커피숖에 가야죠. 커피를 한잔 시키고 자리 앉아서
// 커피숖의 업무 흐름을 파악해야 합니다.
// 커피숖에는 어떤 역활(Role)과 어떤 책임(responsibility)이 있나요.

// 역활?
// 바리스타, 매니저, 알바생, 사장님, 캐시어, 손님.


// Barista, Cashier, guest

class Barista {
public:
    void MakeADrink() {
        cout << "음료를 만듭니다." << endl;
    }
};

class Cashier {
private:
    Barista& _refBari;   // 참조(Agreggation)

public:
    Cashier(Barista& ref)
        : _refBari(ref) {}

    void OrderedDrink() {
        cout << "주문을 받습니다." << endl;
        _refBari.MakeADrink();
    }
};

class Guest {
public:
    void OrderingDrink(Cashier& ref) { // 의존적관계(Dependency) -> 주문할 때만 관계를 맺으면 됨(일시적인 관계)
        cout << "음료를 주문합니다." << endl;
        ref.OrderedDrink();
    }
};



// 객체를 만들 때 관계를 맺는 경우 3가지
// 1. 상속 2. 포함(포함, 참조) 3. 의존적 관계
int main() {
    Barista bari;
    Cashier cashier(bari);   // 바리스타와 포함(참조)
    Guest guest;

    guest.OrderingDrink(cashier);


    return 0;
}