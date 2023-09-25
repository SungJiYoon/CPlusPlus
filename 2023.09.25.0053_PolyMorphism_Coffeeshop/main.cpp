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

class Coffee {
private:
    string _name;

public:
    Coffee()
        : _name("Ŀ��") {}

    string GetName() {
        return _name;
    }
};

class Latte {
private:
    string _name;

public:
    Latte()
        : _name("��") {}

    string GetName() {
        return _name;
    }
};

class Barista {
public:
    // �����ε�
    // ���ᰡ �߰��Ǵ��� �ٸ����� �߰� �ȵ��� ������, ���Ḹ �߰����� ������. ��� ����Լ��� �������ϴ� ����
    void MakeADrink(Coffee& drink) {
        cout << drink.GetName() << "�� ����ϴ�." << endl;
    }

    void MakeADrink(Latte& drink) {
        cout << drink.GetName() << "�� ����ϴ�." << endl;
    }
};

class Cashier {
private:
    Barista& _refBari;   // ����(Agreggation)

public:
    Cashier(Barista& ref)
        : _refBari(ref) {}

    void OrderedDrink(Coffee& drink) {
        cout << drink.GetName() << "�� �ֹ��޽��ϴ�." << endl;
        _refBari.MakeADrink(drink);
    }

    void OrderedDrink(Latte& drink) {
        cout << drink.GetName() << "�� �ֹ� �޽��ϴ�." << endl;
        _refBari.MakeADrink(drink);
    }
};

class Guest {
public:
    void OrderingDrink(Cashier& ref, Coffee& drink) { // ����������(Dependency)
        cout << drink.GetName() << "�� �ֹ��մϴ�." << endl;
        ref.OrderedDrink(drink);
    }

    void OrderingDrink(Cashier& ref, Latte& drink) {
        cout << drink.GetName() << "�� �ֹ� �մϴ�." << endl;
        ref.OrderedDrink(drink);
    }
};


int main() {
    Coffee coffee;
    Latte latte;

    Barista bari;
    Cashier cashier(bari);   // �ٸ���Ÿ�� ����(����)
    Guest guest;

    guest.OrderingDrink(cashier, coffee);
    cout << endl;
    guest.OrderingDrink(cashier, latte);


    return 0;
}