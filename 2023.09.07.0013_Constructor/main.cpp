#include <iostream>
#include <string>

using namespace std;

// 생성자는 안만들면 반드시 필요하기 때문에 컴파일러 자동으로
// 기본생성자를 만들어 줍니다.
// 인자를 받는 생성자를 하나라도 만들면 컴파일러는 기본생성자를 
// 안 만들어 줍니다.
// 반드시 생성자를 만들어 주어야 하는 경우가 있습니다.
// 상수형 멤버변수나 참조형 멤버변수가 있는 경우에는
// 컴파일러가 기본생성자를 만들어 주지 않습니다.
// 직접 생성자를 만들어야 합니다.


class Student {
private:
    string _name;
    int _grade;
    int _classNum;

    const int MAXSTUDENTCOUNT;   // 전체 학생수 (상수형멤버변수)
    int& _specialClassNum;   // 특활반 (참조형 멤버변수)

public:
    // 생성자 초기화 리스트를 통해서 멤버변수를 초기화를 진행하면
    // 객체의 메모리가 할당됨과 동시에 값을 초기화 할 수 있습니다.
    Student(string name, int grade, int classNum, int MAXSTUDENT, int& specialClassNum)
        : _name(name), _grade(grade), _classNum(classNum), MAXSTUDENTCOUNT(MAXSTUDENT), _specialClassNum(specialClassNum) // 생성자 초기화 리스트
    {
        //_name = name;
        //_grade = grade;
        //_classNum = classNum;

        // 상수형멤버변수와 참조형멤버변수를 생성자의 코드 블럭안에서 초기화를 
        // 하려고 하는데 에러가 발생합니다.
        // 생성자의 코드블럭에서 멤버변수에 값을 초기화하는 것은
        // 객체의 메모리할당이 끝난후에 대입연산을 통해서 멤버변수의 값을 초기화 하는 것입니다.

        // 상수형멤버변수와 참조형멤버변수는 메모리가 할당됨과 동시에 초기화가 되어야 합니다.
        // 생성자의 코드 블럭안에서 초기화 할 수가 없습니다.
        // 상수형 멤버변수와 참조형 멤버변수는 생성자 초기화 리스트를 통해서 초기화를 하셔야 합니다.

        //MAXSTUDENTCOUNT = MAXSTUDENT;
        //_specialClassNum = specialClassNum;
    }


    void Info() {
        cout << "이름: " << _name << endl;
        cout << "학년: " << _grade << endl;
        cout << "반: " << _classNum << endl;
        cout << "총학생수: " << MAXSTUDENTCOUNT << endl;
        cout << "특활반: " << _specialClassNum << endl;
    }

};

int main() {
    int specialStudentNum = 11;

    Student st("몬스터", 3, 5, 200, specialStudentNum);

    st.Info();

    cout << endl;

    specialStudentNum = 8;

    st.Info();




    return 0;
}