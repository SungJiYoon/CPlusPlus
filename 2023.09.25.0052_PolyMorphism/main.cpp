#include <iostream>

using namespace std;

// ������
// A��ü�� B��ü���� �޼����� ���� ��(A��ü�� B��ü���� ����Լ��� ȣ���Ѵ�)
// ������ �޼����� �پ��� ������ ���̴� ��

// �����ε�   : ���� �̸��� �Լ��� ����� ��. ��, �Ű������� Ÿ���̳� ������ Ʋ�����Ѵ�.
// �������̵� : ��Ӱ��迡�� �θ��� ����Լ��� �ڽ��� �������ϴ� ��/ �θ��� �����Լ��� �ڽ��� �������ϴ� ���


// �����е��� ���α׷��Ӱ� �Ǿ 
// Ŀ�Ǚ� �������α׷��� ���� �Ƿڹ޾ҽ��ϴ�.
// Ŀ�Ǚ��� ������. Ŀ�Ǹ� ���� ��Ű�� �ڸ� �ɾƼ�
// Ŀ�Ǚ��� ���� �帧�� �ľ��ؾ� �մϴ�.
// Ŀ�Ǚ����� � ��Ȱ(Role)�� � å��(responsibility)�� �ֳ���.

// ��Ȱ?
// �ٸ���Ÿ, �Ŵ���, �˹ٻ�, �����, ĳ�þ�, �մ�.


// Barista, Cashier, guest

class Barista {
public:
    void MakeADrink() {
        cout << "���Ḧ ����ϴ�." << endl;
    }
};

class Cashier {
private:
    Barista& _refBari;   // ����(Agreggation)

public:
    Cashier(Barista& ref)
        : _refBari(ref) {}

    void OrderedDrink() {
        cout << "�ֹ��� �޽��ϴ�." << endl;
        _refBari.MakeADrink();
    }
};

class Guest {
public:
    void OrderingDrink(Cashier& ref) { // ����������(Dependency) -> �ֹ��� ���� ���踦 ������ ��(�Ͻ����� ����)
        cout << "���Ḧ �ֹ��մϴ�." << endl;
        ref.OrderedDrink();
    }
};



// ��ü�� ���� �� ���踦 �δ� ��� 3����
// 1. ��� 2. ����(����, ����) 3. ������ ����
int main() {
    Barista bari;
    Cashier cashier(bari);   // �ٸ���Ÿ�� ����(����)
    Guest guest;

    guest.OrderingDrink(cashier);


    return 0;
}