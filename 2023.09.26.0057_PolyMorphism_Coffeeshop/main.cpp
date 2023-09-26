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
public:
    Drink(){}

    virtual string GetName() {
        return "����";
    }

    virtual void MakeADrink() { // �����Լ�
        cout << "���Ḧ ����ϴ�." << endl;
    }
};

class Coffee : public Drink {
public:
    Coffee(){}

    string GetName() override {
        return "Ŀ��";
    }

    void MakeADrink() override {  // �θ��� �����Լ��� �ڽ��� ������ �������̵�
        cout << "Ŀ�Ǹ� ����ϴ�." << endl;
    }
};

class Latte : public Drink {
public:
    Latte(){}

    string GetName() override {
        return "��";
    }

    void MakeADrink() override {
        cout << "�󶼸� ����ϴ�." << endl;
    }
};

class Cola : public Drink {
public:
    Cola(){}

    string GetName() override {
        return "�ݶ�";
    }

    void MakeADrink() override {
        cout << "�ݶ� ����ϴ�." << endl;
    }
};

class Tea : public Drink {
public:
    Tea(){}

    string GetName() override {
        return "��";
    }

    void MakeADrink() override {
        cout << "���� ����ϴ�." << endl;
    }
};

class BanillaLatte : public Drink {
public:
    BanillaLatte(){}

    string GetName() override  {
        return "�ٴҶ��";
    }

    void MakeADrink() override {
        cout << "�ٴҶ�󶼸� ����ϴ�." << endl;
    }
};

class Cidar : public Drink {
public:
    Cidar(){}

    string GetName() override {
        return "���̴�";
    }

    void MakeADrink() override {
        cout << "���̴ٸ� ����ϴ�." << endl;
    }
};

class Barista {
public:
    void MakeADrink(Drink& drink) {
        cout << "���� ����� ���� ���ῡ�� ��û�մϴ�." << endl;
        drink.MakeADrink();
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
    BanillaLatte banillalatte;
    Cidar cidar;

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
    cout << endl;
    guest.OrderingDrink(cashier, banillalatte);
    cout << endl;
    guest.OrderingDrink(cashier, cidar);
    cout << endl;


    return 0;
}