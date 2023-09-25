#include <iostream>
#include <string>

using namespace std;

enum AnimalType {
    COW,
    PIG,
    CHICKEN
};

class Animal {
protected:
    AnimalType _type;
    string _name;

public:
    Animal(AnimalType type, string name)
        : _type(type), _name(name) {}

    AnimalType GetType() {
        return _type;
    }

    void Speak() {
        cout << _name << " ���մϴ�." << endl;
    }
};

class Pig : public Animal {
public:
    Pig(string name)
        : Animal(PIG, name) {}

    void Speak() {
        cout << _name << "�� �ܲ��մϴ�." << endl;
    }
};

class Cow : public Animal {
public:
    Cow(string name)
        : Animal(COW, name) {}

    void Speak() {
        cout << _name << "�� �����մϴ�." << endl;
    }
};

class Chicken : public Animal {
public:
    Chicken(string name)
        : Animal(CHICKEN, name) {}

    void Speak() {
        cout << _name << "�� ������ �մϴ�." << endl;
    }
};

void InvokeSpeak(Pig* panimal) {
    panimal->Speak();
}

void InvokeSpeak(Cow* panimal) {
    panimal->Speak();
}

void InvokeSpeak(Chicken* panimal) {
    panimal->Speak();
}


void InvokeSpeak(Animal* panimal) {
    // switch-case�� �������� �Ϻη� �̷�����
    if (panimal->GetType() == COW) {
        ((Cow*)panimal)->Speak(); // �ٿ� ĳ����
    }
    else if (panimal->GetType() == PIG) {
        ((Pig*)panimal)->Speak();   // �ٿ� ĳ����
    }
    else if (panimal->GetType() == CHICKEN) {
        ((Chicken*)panimal)->Speak(); // �ٿ� ĳ����
    }
}


int main() {
    Pig pig1("���� 1");
    Pig pig2("���� 2");
    Pig pig3("���� 3");

    Cow cow1("�� 1");
    Cow cow2("�� 2");
    Cow cow3("�� 3");

    Chicken chicken1("�� 1");
    Chicken chicken2("�� 2");
    Chicken chicken3("�� 3");

    // ��ü�� �����ϴ� ���
    // 1. ������ ��ü���� ����� ����
    cout << "������ ��ü���� ����� ����" << endl;
    pig1.Speak();
    pig2.Speak();
    pig3.Speak();

    cow1.Speak();
    cow2.Speak();
    cow3.Speak();

    chicken1.Speak();
    chicken2.Speak();
    chicken3.Speak();


    // 2. ������ Ÿ���� �迭�� ����� ó��
    Pig* pigParray[3] = { &pig1, &pig2, &pig3 };
    Cow* cowParray[3] = { &cow1, &cow2, &cow3 };
    Chicken* chickenParray[3] = { &chicken1, &chicken2, &chicken3 };

    for (int i = 0; i < 3; i++) {
        pigParray[i]->Speak();
        cowParray[i]->Speak();
        chickenParray[i]->Speak();
    }



    // 3. ��ӿ� ���� upcasting�� ����� ����ؼ� �θ�Ÿ���� �迭�� ����� 
    // �ڽĵ��� �ϰ������� �����ؼ� ó��
    cout << endl;
    cout << "UpCasing�� �̿�" << endl;
    Animal* panimal[9] = { &pig1, &cow1, &chicken1, &pig2, &cow2, &chicken2, &pig3, &cow3, &chicken3 };

    for (int i = 0; i < 9; i++) {
        panimal[i]->Speak();
    }

    cout << endl;
    cout << "InvoekSpeak �Լ� ȣ��" << endl; // �ٿ�ĳ����
    for (int i = 0; i < 9; i++) {
        /*
        switch (panimal[i]->GetType()) {
        case COW:
           InvokeSpeak((Cow*)panimal[i]);
           break;

        case PIG:
           InvokeSpeak((Pig*)panimal[i]);
           break;

        case CHICKEN:
           InvokeSpeak((Chicken*)panimal[i]);
           break;

        }
        */
        InvokeSpeak(panimal[i]);
    }

    return 0;
}