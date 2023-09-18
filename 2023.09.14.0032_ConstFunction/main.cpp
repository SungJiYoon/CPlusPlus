#include <iostream>
#include <string>

using namespace std;

class Fruit {
private:
    string _name;        // 과일명
    float _weight;       // 무게
    float _brixDegree;   // 당도

public:
    Fruit(string name, float weight, float brixDegree)
        : _name(name), _weight(weight), _brixDegree(brixDegree)
    {

    }

    string GetName() const {   // const형 멤버함수 (멤버변수의 값을 변경하지 않는 함수)
       //_name = "monster";
        return _name;
    }

    void SetName(string value) {
        _name = value;
    }

    float GetBrixDegree() const {
        return _brixDegree;
    }

    float GetWeight() const {
        return _weight;
    }

    void ShowInfo() {
        cout << "과일명: " << _name << endl;
        cout << "무게: " << _weight << "g" << endl;
        cout << "당도: " << _brixDegree << "%" << endl;
        cout << endl;
    }
};

// 객체를 인자로 전달할때.
// 참조형으로 전달을 합니다.
// const로 인자를 전달 받는 경우에는
// 함수안에서 인자로 전달받은 객체의 값을 변경하지 않겠다는 의미입니다.
// const로 인자를 전달하는 경우 함수안에서 멤버함수를 호출하는 경우에는
// const형 멤버함수만 호출 할 수 있습니다.
void PrintFruit(const Fruit& ref) {
    cout << "과일명: " << ref.GetName() << endl;
    cout << "무게: " << ref.GetWeight() << "g" << endl;
    cout << "당도: " << ref.GetBrixDegree() << "%" << endl;
    cout << endl;

    //ref.SetName("호박");   // 참조형으로 인자를 전달 받게 되는 경우에
                             // 전달받은 인자의 객체의 값을 실수로 변경할수가 있습니다.
}

int main() {
    Fruit fruitArray[3] = {
       {"바나나", 0.3f, 80.0f},
       {"사과", 0.8f, 83.0f},
       {"딸기", 0.2f, 78.0f}
    };

    int length = sizeof(fruitArray) / sizeof(Fruit);

    for (int i = 0; i < length; i++) {
        PrintFruit(fruitArray[i]);
    }

    cout << "변경후" << endl;
    for (int i = 0; i < length; i++) {
        fruitArray[i].ShowInfo();
    }

    // 객체지향의 3대 속성
    // 1. 캡슐화 : 클래스형 데이터 타입을 만드는 방법 / 은닉성(접근제어자) / 추상화
    // 2. 상속 :
    //          계층구조로 맺는것
    //          부모 : base 클래스 / 자식 : derived 클래스(유도된 클래스)
    //          is a 관계 / has a 관계
    //          포함은 2가지로 나뉨 : 생명주기를 같이하는건 Composition(합성) / 생명주기를 같이하지않는건 Aggregation(집합)
    //          상속을 하는 방법 : Generalization 일반화 / Specialization 특수화
    //          일반화 : 여러개의 공통된 내용을 뽑아서 추려낸 다음에 그걸로 클래스를 만들고, 공통된 내용으로 만들어진 클래스를 가지고 상속을 시키는 것
    //          특수화 : 클래스 하나로 여러가지 타입을 쓰게 되어서 분기문을 사용해서 클래스는 비대해지고, 비효율적이 되어간다.
    //                   이럴때 상속을 생각함. 클래스 안에서 특수한 경우에 해당하는 것들을 뽑아낸다.
    //                   아까 처음 클래스에는 일반적인 내용을 둔다.
    //                   이제 역방향으로 상속을 시켜준다. (처음 클래스에 뽑아냈던 클래스들을)
    // 3. 다형성

    return 0;
}