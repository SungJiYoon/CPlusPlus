#include <iostream>
#include <string>

using namespace std;

// ������

// �����е��� ���α׷��Ӱ� �Ǿ 
// Ŀ�Ǚ� �������α׷��� ���� �Ƿڹ޾ҽ��ϴ�.
// Ŀ�Ǚ��� ������. Ŀ�Ǹ� ���� ��Ű�� �ڸ� �ɾƼ�
// Ŀ�Ǚ��� ���� �帧�� �ľ��ؾ� �Ϻ��.
// Ŀ�Ǚ����� � ��Ȱ(Role)�� � å��(responsibility)�� �ֳ���.

// ��Ȱ?
// �ٸ���Ÿ, �Ŵ���, �˹ٻ�, �����, ĳ�þ�, �մ�.


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
        return "����";
    }

};

class Coffee : public Drink {
public:
    Coffee()
        : Drink(COFFEE)
    {}

    string GetName() {
        return "Ŀ��";
    }

};

class Latte : public Drink {
public:
    Latte()
        : Drink(LATTE)
    {}

    string GetName() {
        return "��";
    }

};

class Cola : public Drink {
public:
    Cola()
        : Drink(COLA)
    {}

    string GetName() {
        return "�ݶ�";
    }

};

class Tea : public Drink {
public:
    Tea()
        : Drink(TEA)
    {}

    string GetName() {
        return "��";
    }

};

class Barista {
public:
    void MakeADrink(Drink& drink) {
        cout << drink.GetName() << "�� ����ϴ�." << endl;
    }
};

class Cashier {
private:
    Barista& _refBari;   // ����(Agreggation)

public:
    Cashier(Barista& ref)
        : _refBari(ref) {}

    void OrderedDrink(Drink& drink) {
        cout << drink.GetName() << "�� �ֹ��޽��ϴ�." << endl;
        _refBari.MakeADrink(drink);
    }
};

class Guest {
public:
    void OrderingDrink(Cashier& ref, Drink& drink) { // ����������(Dependency)
        cout << drink.GetName() << "�� �ֹ��մϴ�." << endl;
        ref.OrderedDrink(drink);
    }
};


int main() {
    Coffee coffee;
    Latte latte;
    Cola cola;
    Tea tea;

    Barista bari;
    Cashier cashier(bari);   // �ٸ���Ÿ�� ����(����)
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