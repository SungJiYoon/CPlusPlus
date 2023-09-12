#include <iostream>
#include <string>

using namespace std;

class Monster {
private:
    string _name;
    int _health;
    int _attack;
    int _defense;

    static int MonsterCount;   // ����������� , Ŭ���� ����(��ü�� �������� �ʰ� Ŭ������ �����ִ�), Ŭ���� ������ ��Ʋ� �ϳ��� �������
                               // ������������� ������������ ������ �޽��ϴ�.

public:


    Monster(string name, int health, int attack, int defense)
        : _name(name), _health(health), _attack(attack), _defense(defense)
    {
        cout << "Monster ������ ȣ��" << endl;

        MonsterCount++;
    }

    // �Ҹ��ڴ� ��ü�� �Ҹ�ɶ� �ڵ����� ȣ��Ǿ����� ����Լ��Դϴ�.
    // �Ҹ��ڿ����� ��ü�� ������� �ؾ��ϴ� �Ĵ��۵�, ���ҽ����� �۾���
    ~Monster()   // �Ҹ���
    {
        cout << "Monster �Ҹ��� ȣ��" << endl;
        MonsterCount--;
    }

    static int GetMonsterCount() {   // ��������Լ�, Ŭ�����Լ�
        // ��������Լ��ȿ����� ��������� �����ϸ� �ȵ˴ϴ�.
        //_health = 100;
        // ��������� ��ü�� �����Ǿ������ ������ ������
        // ������ ��������Լ��� ��ü�� �����ϰ� �۵���
        // �׷��� ��������Լ� �ȿ��� ��������� ���ٺҰ�

        return MonsterCount;
    }

    void Info() {
        cout << "���͸�: " << _name << endl;
        cout << "�����: " << _health << endl;
        cout << "���ݷ�: " << _attack << endl;
        cout << "����: " << _defense << endl;

        cout << "���� �Ѽ�: " << MonsterCount << endl << endl;
    }
};

int Monster::MonsterCount = 0; // ������������� �ʱ�ȭ�� Ŭ������ �ܺο��� �ؾ��մϴ�.
                               // ��ü�� �������� �ʱ� ������ �ۿ��� �ʱ�ȭ���������


int main() {

    Monster dragon("dragon", 100, 300, 200);
    cout << "��ü ������ ����: " << Monster::GetMonsterCount() << endl;   // :: ��������������(scoupe ������)

    { // ��ȣ�� ������ �Ҹ��ڰ� ����� �׷� ���� ī���ʹ� -1�� �����
        Monster ogre("ogre", 60, 10, 8);
        cout << "��ü ������ ����: " << Monster::GetMonsterCount() << endl;
        {
            Monster troll("troll", 60, 15, 10);

            cout << "��ü ������ ����: " << Monster::GetMonsterCount() << endl;
        }

        cout << "��ü ������ ����: " << Monster::GetMonsterCount() << endl;
    }

    Monster slime("slime", 30, 20, 5);
    cout << "��ü ������ ����: " << Monster::GetMonsterCount() << endl;

    return 0;
}