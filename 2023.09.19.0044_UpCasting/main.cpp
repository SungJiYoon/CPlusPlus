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
        cout << _name << " 말합니다." << endl;
    }
};

class Pig : public Animal {
public:
    Pig(string name)
        : Animal(PIG, name) {}

    void Speak() {
        cout << _name << "가 꿀꿀합니다." << endl;
    }
};

class Cow : public Animal {
public:
    Cow(string name)
        : Animal(COW, name) {}

    void Speak() {
        cout << _name << "가 음매합니다." << endl;
    }
};

class Chicken : public Animal {
public:
    Chicken(string name)
        : Animal(CHICKEN, name) {}

    void Speak() {
        cout << _name << "이 꼬끼오 합니다." << endl;
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
    // switch-case가 더좋은데 일부러 이렇게함
    if (panimal->GetType() == COW) {
        ((Cow*)panimal)->Speak(); // 다운 캐스팅
    }
    else if (panimal->GetType() == PIG) {
        ((Pig*)panimal)->Speak();   // 다운 캐스팅
    }
    else if (panimal->GetType() == CHICKEN) {
        ((Chicken*)panimal)->Speak(); // 다운 캐스팅
    }
}


int main() {
    Pig pig1("돼지 1");
    Pig pig2("돼지 2");
    Pig pig3("돼지 3");

    Cow cow1("소 1");
    Cow cow2("소 2");
    Cow cow3("소 3");

    Chicken chicken1("닭 1");
    Chicken chicken2("닭 2");
    Chicken chicken3("닭 3");

    // 객체를 관리하는 방법
    // 1. 각각의 객체에게 명령을 수행
    cout << "각각의 객체에게 명령을 수행" << endl;
    pig1.Speak();
    pig2.Speak();
    pig3.Speak();

    cow1.Speak();
    cow2.Speak();
    cow3.Speak();

    chicken1.Speak();
    chicken2.Speak();
    chicken3.Speak();


    // 2. 각각의 타입의 배열을 만들고 처리
    Pig* pigParray[3] = { &pig1, &pig2, &pig3 };
    Cow* cowParray[3] = { &cow1, &cow2, &cow3 };
    Chicken* chickenParray[3] = { &chicken1, &chicken2, &chicken3 };

    for (int i = 0; i < 3; i++) {
        pigParray[i]->Speak();
        cowParray[i]->Speak();
        chickenParray[i]->Speak();
    }



    // 3. 상속에 따른 upcasting의 기능을 사용해서 부모타입의 배열을 만들고 
    // 자식들을 일괄적으로 저장해서 처리
    cout << endl;
    cout << "UpCasing을 이용" << endl;
    Animal* panimal[9] = { &pig1, &cow1, &chicken1, &pig2, &cow2, &chicken2, &pig3, &cow3, &chicken3 };

    for (int i = 0; i < 9; i++) {
        panimal[i]->Speak();
    }

    cout << endl;
    cout << "InvoekSpeak 함수 호출" << endl; // 다운캐스팅
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