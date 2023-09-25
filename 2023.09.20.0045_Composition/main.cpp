#include <iostream>
#include <string>

using namespace std;

// ����
// ����(Composition): ���Ѱ��� (�����ֱ⸦ ���� �Ҷ�) // �� Ŭ������ �ٸ� Ŭ������ ����� ���� ���� ��
// ����(Agreggation): ���Ѱ��� (�����ֱ⸦ �޸� �Ҷ�)

class Heart {
private:
    float _purseRate;

public:
    Heart(float purseRate)
        : _purseRate(purseRate)
    {
        cout << "-- Heart�� ������ --" << endl;
    }

    ~Heart() {
        cout << "-- Heart�� �Ҹ��� --" << endl;
    }

    void Check() {
        cout << "������ " << _purseRate << "(min)�� �ٰ� �ֽ��ϴ�." << endl;
    }
};

class Watch {
private:
    string _color;

public:
    Watch(string color)
        : _color(color)
    {
        cout << "-- Watch ������ --" << endl;
    }

    ~Watch() {
        cout << "-- Watch �Ҹ��� --" << endl;
    }

    string GetColor() {
        return _color;
    }

    void ShowTime() {
        cout << _color << "�ð��� ����ð��� 12:00 �Դϴ�." << endl;
    }
};

class Human {
private:
    string _name;
    Heart _heart;  
    Watch* _pWatch;   

public:
    Human(string name, float purseRate, Watch* pWatch)
        : _name(name), _heart(purseRate), _pWatch(pWatch)
    {
        cout << "-- Human ������ --" << endl;
    }

    ~Human() {
        cout << "-- Human �Ҹ��� --" << endl;
    }

    void CheckHealth() {
        cout << _name << "_";
        _heart.Check();
    }

    void ChangeWatch(Watch* pWatch) {
        _pWatch = pWatch;
    }

    void DisplayTime() {
        cout << _name << "_";
        _pWatch->ShowTime();
    }
};

int main() {
    Watch redWatch("������");
    Watch blackWatch("������");

    cout << "------------------- ���α׷� ���� ------------------------" << endl;
    {
        Human human("�޽�", 70.0f, &redWatch);

        human.CheckHealth();
        human.DisplayTime();

        cout << "�ð踦 �����ð�� ����" << endl;
        human.ChangeWatch(&blackWatch);
        human.DisplayTime();


    }
    cout << "------------------- ���α׷� ���� ------------------------" << endl;

    cout << "End" << endl;
    return 0;
}