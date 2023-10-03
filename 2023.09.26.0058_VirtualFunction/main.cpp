#include <iostream>

using namespace std;

// __vfptr : 가상함수테이블의 주소값을 가지고 있음
class Parent {
public:
    void Print() {   // 일반 멤버함수
        cout << "Parent::Print() " << endl;
    }

    virtual void VPrint1() {   // 가상함수
        cout << "Parent::VPrint1() " << endl;
    }

    virtual void VPrint2() {   // 가상함수
        cout << "Parent::VPrint2() " << endl;
    }

    virtual void VPrint3() {   // 가상함수
        cout << "Parent::VPrint3() " << endl;
    }
};

class Child1 : public Parent {
public:
    void Print() {   // 일반멤버함수
        cout << "Child1::Print()" << endl;
    }

    void VPrint1() override {  // 오버라이드된 가상함수
        cout << "Child1::VPrint1()" << endl;
    }
};

class Child2 : public Parent {
public:
    void Print() {   // 일반 멤버함수
        cout << "Child2::Print()" << endl;
    }

    void VPrint2() override {   // 오버라이드된 가상함수
        cout << "Child2::VPrint2()" << endl;
    }
};

class Child3 : public Parent {
public:
    void Print() { // 일반멤버함수
        cout << "Child3::Print()" << endl;
    }

    void VPrint3() override {   // 오버라이드된 가상함수
        cout << "Child3::VPrint3()" << endl;
    }
};

// 일반 멤버함수 호출
void FuncPrint(Parent& ref) {
    //ref.Print();
    ref.Parent::Print(); // 정적바인딩 : 컴파일시 (실행파일을 만들때) 어느 함수를 호출할 지 결정하는 것
}

void FuncPrint(Child1& ref) { // 오버로딩
    ref.Print();
}

void FuncPrint(Child2& ref) { // 오버로딩
    ref.Print();
}

void FuncPrint(Child3& ref) { // 오버로딩
    ref.Print();
}

// 가상함수 호출
void FuncVPrint1(Parent& ref) { // 가상함수는 들어오는 타입에 준해서 작동한다.(실행중에 인자값이 들어온다.) 그래서 실행파일 만들 때 결정할 수가 없음.
    ref.VPrint1(); // 결정이 유보된다. 동적바인딩 : 실행중에 어느 함수를 호출할지 결정하는 것
    //ref.__vfptr[0]();
}

void FuncVPrint2(Parent& ref) {
    ref.VPrint2();
    //ref.__vfptr[1]();
}

int main() {
    Parent parent;
    Child1 child1;
    Child2 child2;
    Child3 child3;

    // 일반멤버함수 호출
    cout << "일반멤버함수 호출 Call FuncPrint" << endl;
    FuncPrint(parent);
    FuncPrint(child1);
    FuncPrint(child2);
    FuncPrint(child3);

    // 가상 멤버함수 호출
    cout << endl;
    cout << "가상 멤버함수  Call FuncVPrint1" << endl;
    FuncVPrint1(parent);
    FuncVPrint1(child1);
    FuncVPrint1(child2);
    FuncVPrint1(child3);


    cout << endl;
    cout << "가상 멤버함수  Call FuncVPrint2" << endl;
    FuncVPrint2(parent);
    FuncVPrint2(child1);
    FuncVPrint2(child2);
    FuncVPrint2(child3);

    return 0;
}