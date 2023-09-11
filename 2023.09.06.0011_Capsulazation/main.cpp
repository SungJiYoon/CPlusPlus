#include <iostream>
#include <string>

using namespace std;

// 축구게임에서 필요한 손흥민의 데이타를 추상화 하시고
// 클래스로 캡슐화한 후에 객체를 만들고 데이타를 채우고
// 출력해보세요..

class SoccerSon {
private:
    // 일반변수와 멤버변수를 구별하기 쉽게 멤버변수앞에 접두사를 붙이는 것이 좋습니다.
    string _name; // 멤버변수, attribute, property, field
    float _speed;
    float _weight;
    float _height;
    string _skill;

public:
    // 생성자 // 클래스명과 동일한 이름의 함수, 리턴값은 없습니다.
    // 아무 인자도 받지 않는 생성자를 기본 생성자라고 합니다.
    // 생성자를 안만들면 생성자는 반드시 필요하기 때문에
    // 컴파일러가 기본생성자를 자동으로 만들어 줍니다.
    // 생성자의 역활은
    // 객체가 생성될때 전단 작업을 생성자에서 하시면됩니다.
    // 보통 멤버변수를 초기화하는 작업을 합니다.
    SoccerSon() {
        cout << "SoccerSon 기본 생성자" << endl;
    }

    // 인자를 받는 생성자
    SoccerSon(string name, float speed, float weight, float height, string skill) {
        cout << "SoccerSon 인자를 받는 생성자" << endl;
        _name = name;
        _speed = speed;
        _weight = weight;
        _height = height;
        _skill = skill;
    }

    void SetName(string value) { // 멤버함수, 메소드, behaviour
        _name = value;
    }

    string GetName() {
        return _name;
    }

    void SetSpeed(float value) {
        _speed = value;
    }

    float GetSpeed() {
        return _speed;
    }

    void SetWeight(float value) {
        _weight = value;
    }

    float GetWeight() {
        return _weight;
    }

    void SetHeight(float value) {
        _height = value;
    }

    float GetHeight() {
        return _height;
    }

    void SetSkill(string value) {
        _skill = value;
    }

    string GetSkill() {
        return _skill;
    }

};



int main() {
    // 객체가 만들어 질때 자동으로 호출되어지는 멤버함수가 있습니다.
    // 객체는 이 함수가 호출되어야지만 온전한 객체로 생성이 됩니다.
    // 이 함수를 생성자(Constructor)라고 합니다.
    // 객체가 메모리에 존재하고 있는, 할당되어 있는 상태를 instence라고 한다.
    // 메모리에 할당할때 생성자가 작동된다.
    // 생성자가 호출되어야지만 온전한 객체로써 메모리에 할당되는 것이다.
    SoccerSon player;   // 기본 생성자가 호출


    player.SetName("손흥민");
    player.SetSpeed(10.3f);
    player.SetWeight(83.0f);
    player.SetHeight(183.0f);
    player.SetSkill("OverHeadKick");

    cout << "이름: " << player.GetName() << endl;
    cout << "100미터 달리기: " << player.GetSpeed() << endl;
    cout << "몸무게: " << player.GetWeight() << endl;
    cout << "신장: " << player.GetHeight() << endl;
    cout << "주요스킬: " << player.GetSkill() << endl;

    cout << endl;

    SoccerSon player2("손흥민2", 9.9f, 85.0f, 189.0f, "슛팅");   // 인자를 받는 생성자가 호출

    cout << "이름: " << player2.GetName() << endl;
    cout << "100미터 달리기: " << player2.GetSpeed() << endl;
    cout << "몸무게: " << player2.GetWeight() << endl;
    cout << "신장: " << player2.GetHeight() << endl;
    cout << "주요스킬: " << player2.GetSkill() << endl;



    return 0;
}