#include <iostream>
#include <string>

using namespace std;

class Building {
private:
    string _name;
    float _area;
    int _maxFloor;

public:
    Building(string name, float area, int maxFloor)
        : _name(name), _area(area), _maxFloor(maxFloor) {}

    string GetName() {
        return _name;
    }

    float GetArea() {
        return _area;
    }

    int GetMaxFloor() {
        return _maxFloor;
    }

    void CheckFloor(int floor) {
        switch (floor) {
        case -1:
            cout << "지하 1층 배수 시스템을 체크합니다." << endl;
            break;

        case 1:
            cout << "1층 엘리베이터 시스템을 체크합니다." << endl;
            break;

        case 2:
            cout << "2층 방화 시스템을 체크합니다." << endl;
            break;

        default:
            cout << floor << "층 일반 시스템을 체크합니다." << endl;
            break;
        }
    }

    // 멤버 함수는 메모리 공간에 저장되어있다 / 메인함수도 메모리에 있다
    // 메인 함수에 있는 명령어를 CPU가 읽어나간다
    // 메인 함수의 명령어를 읽어가다가 CheckAllFloor()를 호출하라는 줄을 만나면
    // CehckAllFloor() 쪽으로 instruction pointer가 바뀐다
    // 함수 호출은 고비용이다
    // 함수안에 명령어 다 끝나고 메모리 공간에 저장한 다음에 메인으로 돌아온다
    // 만약 백만번을 호출한다 했을 때 저장하고 불러오고 하는 부분이 오버헤드가 크다
    // 이럴땐 함수호출보다는 그냥 함수 안에 있는 코드를 그냥 박아버리는게 더 나을 수가 있다
    // 그래서 inline 함수를 사용한다 
    // inline 함수는 함수를 함수의 "선언부" 안에다가 구현을 해두면 컴파일러가 함수호출말고 코드를 그냥 박아주는 것이다
    void CheckAllFloor() {
        cout << endl;
        cout << "빌딩의 모든 시스템을 체크합니다." << endl;

        for (int i = 0; i < _maxFloor; i++) {
            CheckFloor(i);
        }
    }
};

// C++언어는 태생적으로 C언어의 구문구조를 기반으로 개발이 되었습니다.
// 선언부(.h, 헤더파일), 구현부(.cpp)로 나누어서 개발하도록 되어있습니다.
// 클래스 내부에서 함수의 구현을 하는 경우(구현부가 있는 경우) 컴파일러는
// inline 함수로 만들어 달라는 요청으로 받아드립니다.
// 반드시 inline함수로 만들어 지는 것은 아닙니다.
// 컴파일러가 판단해서 inline 함수로 만들 수 있으면 inline함수로
// 처리하고 못하는 경우에는 함수로 만듭니다.
  
int main() {
    Building starTower("스타타워", 112300.23f, 23);

    cout << "빌딩명: " << starTower.GetName() << endl;
    cout << "전체면적: " << starTower.GetArea() << endl;
    cout << "전체층수: " << starTower.GetMaxFloor() << endl;

    starTower.CheckFloor(-1);

    cout << "CheckAllFloor" << endl;

    starTower.CheckAllFloor();

    return 0;
}