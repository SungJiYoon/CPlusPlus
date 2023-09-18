#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Monster {
private:
    string _name;
    int _health;
    int _attack;
    int _defense;

public:
    // �⺻ �����ڸ� ȣ���ؼ� ��ü �迭�� ������ �մϴ�.
    Monster()
        : _name(""), _health(0), _attack(0), _defense(0)
    {
        cout << "Monster �⺻������" << endl;
    }


    Monster(string name, int health, int attack, int defense)
        : _name(name), _health(health), _attack(attack), _defense(defense)
    {
        cout << "Monster ������" << endl;
    }

    ~Monster() {
        cout << "Monster �Ҹ���" << endl;
    }

    void Init(string name, int health, int attack, int defense) {
        _name = name;
        _health = health;
        _attack = attack;
        _defense = defense;
    }

    void Attack() {
        cout << _name << "�� �����Ѵ�." << endl;
    }

    void Defense() {
        cout << _name << "�� ����Ѵ�.";
    }

    void Info() {
        cout << "----------------------------" << endl;
        cout << "���͸�: " << _name << endl;
        cout << "�����: " << _health << endl;
        cout << "���ݷ�: " << _attack << endl;
        cout << "����: " << _defense << endl;
        cout << "----------------------------" << endl << endl;
    }
};


// Monster* parray = new Monster[count];
// ������ �ּҰ��� �����ϴ� ���� ��ü �迭�� ��� delete[] ������Ѵ�.
// 
// ������ �ּҰ��� �����ϴ� �迭�� ������Ÿ���� Monster**
// Monster** pparray; (���� �ּҰ��� �����ϴ� �迭�� �ּҰ��� �����ϴ� ����)
// pparray = new Monster * [count]; �� ��ü �ϳ��� ����� �� �� �ִ�. ����� �ű� NULL�� �ָ� �ȴ�.
int main() {
    // ���� ��ü �迭
    int count = 0;
    int index = 0;
    char buff[30];

    Monster** pparray;

    cout << "���� ������ �������� �Է��ϼ���: ";
    cin >> count;

    pparray = new Monster * [count];   // Monster* �� �����ϴ� ���� �迭�� �����.

    for (int i = 0; i < count; i++) {
        sprintf(buff, "DynamicObjectMonster_%d", i);

        pparray[i] = new Monster(buff, i * 3, i * 4, i * 2);   // Monster* �����ϴ� �迭�� ���� ���ڸ� �޴� �����ڸ� ȣ���ؼ� Monster��ü�� �����
                                                  // ��ü�� �ּҰ��� �迭�� �����Ѵ�.
    }

    for (int i = 0; i < count; i++) {
        pparray[i]->Attack();   // pparray�� ��ҿ� ����� ���� Monster��ü�� �ּҰ��Դϴ�.
                          // ��ü�� �ּҰ����� ����� �����Ҷ��� ->(ȭ��ǥ������)�� ����մϴ�.
    }

    cout << endl;

    cout << "�����Ϸ��� �ϴ� ��ü�� �ε��� ��ȣ�� �Է��ϼ���.: ";

    cin >> index;

    delete pparray[index];   // pparray Monster* �迭�� ����Ǿ��ִ� index ��° ��ü�� ��ȯó��

    pparray[index] = NULL;   // Monster* �迭�� ��ü�� ������ �ε����� ��������� NULL�� �����Ѵ�.

    for (int i = 0; i < count; i++) {
        if (pparray[i] != NULL)
        {
            pparray[i]->Attack();
        }   
    }

    // ��ü ��ȯ ó��
    // Monster* (������ �ּҰ�)�� �����ϴ� �迭�� ����� ������ ��ü�� ��ȯ ó���Ѵ�.
    // NULL�� ��ȯó������ ����. �̹� ��ȯó���Ʊ��� �ϰ� �޾Ƶ���.
    for (int i = 0; i < count; i++) {
        delete pparray[i];
    }

    // Monster* (������ �ּҰ�)�� �����ϴ� �����迭�� ��ȯ ó��
    delete[] pparray;

    Monster array[10];

    return 0;
}