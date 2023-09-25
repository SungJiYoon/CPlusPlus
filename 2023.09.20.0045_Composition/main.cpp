#include <iostream>
#include <string>

using namespace std;

// 포함
// 포함(Composition): 강한결합 (생명주기를 같이 할때) // 한 클래스가 다른 클래스를 멤버로 갖고 있을 때
// 참조(Agreggation): 약한결합 (생명주기를 달리 할때)

class Heart {
private:
    float _purseRate;

public:
    Heart(float purseRate)
        : _purseRate(purseRate)
    {
        cout << "-- Heart의 생성자 --" << endl;
    }

    ~Heart() {
        cout << "-- Heart의 소멸자 --" << endl;
    }

    void Check() {
        cout << "심장이 " << _purseRate << "(min)로 뛰고 있습니다." << endl;
    }
};

class Watch {
private:
    string _color;

public:
    Watch(string color)
        : _color(color)
    {
        cout << "-- Watch 생성자 --" << endl;
    }

    ~Watch() {
        cout << "-- Watch 소멸자 --" << endl;
    }

    string GetColor() {
        return _color;
    }

    void ShowTime() {
        cout << _color << "시계의 현재시간은 12:00 입니다." << endl;
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
        cout << "-- Human 생성자 --" << endl;
    }

    ~Human() {
        cout << "-- Human 소멸자 --" << endl;
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
    Watch redWatch("빨간색");
    Watch blackWatch("검정색");

    cout << "------------------- 프로그램 시작 ------------------------" << endl;
    {
        Human human("메시", 70.0f, &redWatch);

        human.CheckHealth();
        human.DisplayTime();

        cout << "시계를 검정시계로 변경" << endl;
        human.ChangeWatch(&blackWatch);
        human.DisplayTime();


    }
    cout << "------------------- 프로그램 종료 ------------------------" << endl;

    cout << "End" << endl;
    return 0;
}