#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Monster {
private:
    string _name;
    int _health;
    int _attack;
    int _defense;

public:
    Monster(string name, int health, int attack, int defense)
        : _name(name), _health(health), _attack(attack), _defense(defense)
    {
        cout << _name << "������" << endl;
    }

    ~Monster() {
        cout << _name << "�Ҹ���" << endl;
    }

    void Attack() {
        cout << _name << "�� �����Ѵ�." << endl;
    }

    void Defense() {
        cout << _name << "�� ����Ѵ�." << endl;
    }

    void Info() {
        cout << "���͸�: " << _name << endl;
        cout << "�����: " << _health << endl;
        cout << "���ݷ�: " << _attack << endl;
        cout << "����: " << _defense << endl;
    }

};

int main() {
    // �������� ��ü�� �����Ҷ��� new �����ڸ� ����ؾ� �մϴ�.
    // ��ü�� �����ɶ� �����ڰ� ȣ��Ǿ������ ������ ��ü�� ������
    // �� �ֽ��ϴ�.

    // malloc�� ����ؼ� ��ü�� ����
    // malloc���� ������ü�� ����� �ȵ˴ϴ�.
    // malloc�� �����ڸ� ȣ������ �ʽ��ϴ�.
    // free�� �Ҹ��ڸ� ȣ������ �ʽ��ϴ�.
    // malloc�� ����ؼ��� ������ ��ü�� ������ ���� �����ϴ�.
    cout << "c�� malloc �Լ��� ���" << endl;
    Monster* cpmons = (Monster*)malloc(sizeof(Monster));
    free(cpmons);


    cout << "new ������ ���" << endl;
    // new �����ڸ� ����ؼ� ��ü�� ����
    // ��ü�� �����Ҷ��� new �����ڸ� ����ؾ� �մϴ�.
    // new �����ڴ� ������ ȣ�� ��Ű��
    // delete �����ڴ� �Ҹ��ڸ� ȣ�� ���� �ݴϴ�.
    Monster* pmons = new Monster("�巡��", 100, 30, 20);   // ������ ȣ��
    pmons->Attack(); // �ּҰ��� ����ϴϱ� -> �����
    cout << endl;
    pmons->Defense();
    cout << endl;
    pmons->Info();

    delete pmons;   // �Ҹ��ڰ� ȣ��


    return 0;
}