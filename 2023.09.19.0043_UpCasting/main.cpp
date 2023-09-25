#include <iostream>

using namespace std;

class Parent {
public:
    int _pvalue;

public:
    Parent()
        : _pvalue(0) {}

    Parent(int pvalue)
        : _pvalue(pvalue) {}


    void ShowInfo() {
        cout << "Parent::_pvalue = " << _pvalue << endl;
    }

};

class Child : public Parent {
public:
    int _cvalue;

public:
    Child()
        : Parent(0), _cvalue(0) {}

    Child(int pvalue, int cvalue)
        : Parent(pvalue), _cvalue(cvalue) {}


    void ShowInfo() {
        cout << "Child::Parent::_pvalue = " << _pvalue << endl;
        cout << "Child::_cvalue = " << _cvalue << endl;
    }

};

int main() {
    Parent parent(5);

    Child child(10, 20);

    parent.ShowInfo();

    child.ShowInfo(); // 자식이 일반멤버함수를 만들지 않으면 부모꺼가 호출된다.
                      // 자식에 있으면 자식꺼가 호출된다.

    parent = child; // 일반적으로 데이터 타입이 다르면 대입을 할 수 없다. 근데 상속관계에서는 부모타입에 자식타입을 대입할 수 있다.(업캐스팅)
                    // 근데 이렇게 잘 안쓰고 보통 참조타입이나 포인터타입으로 대입한다.

    // 부모의 데이타 타입에 자식의 데이타 타입을
    // 대입하는 것을 UpCasting(업캐스팅)
    // 자식의 타입을 부모의 참조타입이나 포인터타입에 대입하는 것을
    // 업캐스팅이라합니다.

    //child = parent;  // 자식의 타입에 부모의 타입을 대입하는 것을 다운캐스팅
                       // 다운캐스팅은 기본적으로 허용되지 않습니다.
                       // 업캐스팅은 자식이 부모의 부분을 가지고 있으니까 그부분만 대입되고 자식의 데이터값은 유실된다.(허용)
                       // 반면 부모는 자식의 데이터값을 가지고 있지 않으니까 대입할 수 없다
                       // 다만 허용되는 경우가 있다. 그건 밑에서 보도록.

    cout << endl;

    cout << "Up Casting" << endl;
    cout << "참조타입으로 전달" << endl;

    // 참조타입은 한 번 주소가 설정되면 주소값을 변경할 수 없는 포인터형 변수라고 생각하면 된다.
    Parent& refp = child; // 업캐스팅(UpCasting) : 부모의 참조타입이나 포인터타입으로 자식의 객체를 받는 것.

    refp.ShowInfo();   // refp는 Child 타입의 child 객체를 참조하지만 refp의 타입은 Parent& (Parent참조타입)이기
                       // 때문에 child객체의 영역중에 Parent의 영역만 접근이 가능합니다.
                       // 그래서 Parent의 ShowInfo()가 호출된다.

    // refp는 Parent& 타입인데 Child&으로 형변환
    Child& refc = (Child&)refp; // Child -> Parent -> Child 이러한 다운캐스팅은 허용이 됩니다.

    refc.ShowInfo();   // Child타입의 ShowInfo함수가 호출됨

    cout << endl;
    cout << "포인터 타입으로 전달" << endl;

    Parent* pparent = &child;   // 업캐스팅

    pparent->ShowInfo();      // pparent가 Parent* 타입이어서 Parent타입의 ShowInfo함수가 호출 됩니다.

    Child* pchild = (Child*)pparent;   // 다운 캐스팅 Child* -> Parent* -> Child*

    pchild->ShowInfo();


    return 0;
}
