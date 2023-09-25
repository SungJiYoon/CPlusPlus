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

class Drink {
private:
    string _name;

public:
    Drink(string name)
        : _name(name) {}

    string GetName() {
        return _name;
    }

};

class Coffee : public Drink {
public:
    Coffee()
        : Drink("Ŀ��") {}
};

class Latte : public Drink {
public:
    Latte()
        : Drink("��") {}
};

class Cola : public Drink {
public:
    Cola()
        : Drink("�ݶ�") {}
};

class Tea : public Drink {
public:
    Tea()
        : Drink("��") {}
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