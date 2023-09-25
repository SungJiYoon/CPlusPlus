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

    child.ShowInfo(); // �ڽ��� �Ϲݸ���Լ��� ������ ������ �θ𲨰� ȣ��ȴ�.
                      // �ڽĿ� ������ �ڽĲ��� ȣ��ȴ�.

    parent = child; // �Ϲ������� ������ Ÿ���� �ٸ��� ������ �� �� ����. �ٵ� ��Ӱ��迡���� �θ�Ÿ�Կ� �ڽ�Ÿ���� ������ �� �ִ�.(��ĳ����)
                    // �ٵ� �̷��� �� �Ⱦ��� ���� ����Ÿ���̳� ������Ÿ������ �����Ѵ�.

    // �θ��� ����Ÿ Ÿ�Կ� �ڽ��� ����Ÿ Ÿ����
    // �����ϴ� ���� UpCasting(��ĳ����)
    // �ڽ��� Ÿ���� �θ��� ����Ÿ���̳� ������Ÿ�Կ� �����ϴ� ����
    // ��ĳ�����̶��մϴ�.

    //child = parent;  // �ڽ��� Ÿ�Կ� �θ��� Ÿ���� �����ϴ� ���� �ٿ�ĳ����
                       // �ٿ�ĳ������ �⺻������ ������ �ʽ��ϴ�.
                       // ��ĳ������ �ڽ��� �θ��� �κ��� ������ �����ϱ� �׺κи� ���Եǰ� �ڽ��� �����Ͱ��� ���ǵȴ�.(���)
                       // �ݸ� �θ�� �ڽ��� �����Ͱ��� ������ ���� �����ϱ� ������ �� ����
                       // �ٸ� ���Ǵ� ��찡 �ִ�. �װ� �ؿ��� ������.

    cout << endl;

    cout << "Up Casting" << endl;
    cout << "����Ÿ������ ����" << endl;

    // ����Ÿ���� �� �� �ּҰ� �����Ǹ� �ּҰ��� ������ �� ���� �������� ������� �����ϸ� �ȴ�.
    Parent& refp = child; // ��ĳ����(UpCasting) : �θ��� ����Ÿ���̳� ������Ÿ������ �ڽ��� ��ü�� �޴� ��.

    refp.ShowInfo();   // refp�� Child Ÿ���� child ��ü�� ���������� refp�� Ÿ���� Parent& (Parent����Ÿ��)�̱�
                       // ������ child��ü�� �����߿� Parent�� ������ ������ �����մϴ�.
                       // �׷��� Parent�� ShowInfo()�� ȣ��ȴ�.

    // refp�� Parent& Ÿ���ε� Child&���� ����ȯ
    Child& refc = (Child&)refp; // Child -> Parent -> Child �̷��� �ٿ�ĳ������ ����� �˴ϴ�.

    refc.ShowInfo();   // ChildŸ���� ShowInfo�Լ��� ȣ���

    cout << endl;
    cout << "������ Ÿ������ ����" << endl;

    Parent* pparent = &child;   // ��ĳ����

    pparent->ShowInfo();      // pparent�� Parent* Ÿ���̾ ParentŸ���� ShowInfo�Լ��� ȣ�� �˴ϴ�.

    Child* pchild = (Child*)pparent;   // �ٿ� ĳ���� Child* -> Parent* -> Child*

    pchild->ShowInfo();


    return 0;
}
