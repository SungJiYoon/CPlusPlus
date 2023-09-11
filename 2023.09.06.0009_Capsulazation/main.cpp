#include <iostream>
#include <string>


using namespace std;

/*
주민번호, 거주지, 가족, 나이, 키, 몸무게, 연봉
연락처, 지문
*/

// 주민번호(문자열), 거주지(문자열), 나이(정수형), 연락처(문자열)


// class 클래스명 {
//  데이타;
// };
// 추상화한 데이타를 클래스 키워드로
// 묶는 것을 캡슐화
// 캡슐화를 하면 클래스형 데이타 타입을 만든겁니다.
// Son 이라는 클래스형 데이타 타입을 만든겁니다.
class Son {
private:
    string juminNum;   // 멤버변수 (객체의 속성)
    string address;
    int age;
    string phoneNum;

public:

    // 멤버변수에 접근할때 Set/Get함수를 사용해서 접근하는 경우
    // 디버깅용이합니다. 저장되는 값의 무결성검사, 유효성검사가 용이합니다.
    void SetJumiNum(string value) { // 멤버함수 (객체의 행동)
        juminNum = value;
    }

    string GetJuminNum() {
        return juminNum;
    }

    void SetAddress(string value) {
        address = value;
    }

    string GetAddress() {
        return address;
    }

    void SetAge(int value) {

        if (value < 1) {
            age = 1;
        }
        else if (value > 200) {
            age = 200;
        }
        else {
            age = value;
        }

    }

    int GetAge() {
        return age;
    }

    void SetPhoneNum(string value) {
        phoneNum = value;
    }

    string GetPhoneNum() {
        return phoneNum;
    }
};

// 캡슐화의 기본정책은 정보은닉
// 정보은닉은 캡슐화한 데이타를 외부에 절대 안보여 주겠다(공개하지 않겠다.)
// 객체지향은 객체간의 상호작용으로 프로그램이 작동하는 패러다임인데
// 정보은닉을 하면 상호작용을 할 수가 없습니다.
// 클래스안의 멤버에 대한 접근을 제어해야할 필요성이 있습니다.
// 이런 역활을 하는 것을 접근 제어자라고 합니다.
// 접근제어자에는
// private // 클래스내부의 멤버를 철저하게 감추겠다. (기본)
// protected // 자식에게는 접근 허용, 외부에서는 접근 불허
// public // 외부에 공개

// 멤버변수는 외부에서 바로 접근하는 것을 허용하지 말라고 합니다.(권고사항)
// 멤버함수를 통해서 접근하라고 합니다.
// 멤버변수에 접근할때 사용하는 함수를 Set/Get 함수라고 합니다.
// 값을 변경하는 함수를 Set함수
// 값을 가져오는 함수를 Get함수


int main() {
    Son a;

    // 클래스형 변수의 멤버에 접근할때 .(period 연산자)를 사용합니다.
    a.SetJumiNum("111111111111");
    a.SetAddress("런던");
    a.SetAge(33);
    a.SetPhoneNum("222-2222-2222");


    cout << "주민번호: " << a.GetJuminNum() << endl;
    cout << "주소: " << a.GetAddress() << endl;
    cout << "나이: " << a.GetAge() << endl;
    cout << "전화번호: " << a.GetPhoneNum() << endl;

    Son b;

    b.SetAge(400);



    return 0;
}