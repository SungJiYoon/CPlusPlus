#include <iostream>
#include <string>

using namespace std;

// �����ڴ� �ȸ���� �ݵ�� �ʿ��ϱ� ������ �����Ϸ� �ڵ�����
// �⺻�����ڸ� ����� �ݴϴ�.
// ���ڸ� �޴� �����ڸ� �ϳ��� ����� �����Ϸ��� �⺻�����ڸ� 
// �� ����� �ݴϴ�.
// �ݵ�� �����ڸ� ����� �־�� �ϴ� ��찡 �ֽ��ϴ�.
// ����� ��������� ������ ��������� �ִ� ��쿡��
// �����Ϸ��� �⺻�����ڸ� ����� ���� �ʽ��ϴ�.
// ���� �����ڸ� ������ �մϴ�.


class Student {
private:
    string _name;
    int _grade;
    int _classNum;

    const int MAXSTUDENTCOUNT;   // ��ü �л��� (������������)
    int& _specialClassNum;   // ƯȰ�� (������ �������)

public:
    // ������ �ʱ�ȭ ����Ʈ�� ���ؼ� ��������� �ʱ�ȭ�� �����ϸ�
    // ��ü�� �޸𸮰� �Ҵ�ʰ� ���ÿ� ���� �ʱ�ȭ �� �� �ֽ��ϴ�.
    Student(string name, int grade, int classNum, int MAXSTUDENT, int& specialClassNum)
        : _name(name), _grade(grade), _classNum(classNum), MAXSTUDENTCOUNT(MAXSTUDENT), _specialClassNum(specialClassNum) // ������ �ʱ�ȭ ����Ʈ
    {
        //_name = name;
        //_grade = grade;
        //_classNum = classNum;

        // �������������� ��������������� �������� �ڵ� ���ȿ��� �ʱ�ȭ�� 
        // �Ϸ��� �ϴµ� ������ �߻��մϴ�.
        // �������� �ڵ������ ��������� ���� �ʱ�ȭ�ϴ� ����
        // ��ü�� �޸��Ҵ��� �����Ŀ� ���Կ����� ���ؼ� ��������� ���� �ʱ�ȭ �ϴ� ���Դϴ�.

        // �������������� ��������������� �޸𸮰� �Ҵ�ʰ� ���ÿ� �ʱ�ȭ�� �Ǿ�� �մϴ�.
        // �������� �ڵ� ���ȿ��� �ʱ�ȭ �� ���� �����ϴ�.
        // ����� ��������� ������ ��������� ������ �ʱ�ȭ ����Ʈ�� ���ؼ� �ʱ�ȭ�� �ϼž� �մϴ�.

        //MAXSTUDENTCOUNT = MAXSTUDENT;
        //_specialClassNum = specialClassNum;
    }


    void Info() {
        cout << "�̸�: " << _name << endl;
        cout << "�г�: " << _grade << endl;
        cout << "��: " << _classNum << endl;
        cout << "���л���: " << MAXSTUDENTCOUNT << endl;
        cout << "ƯȰ��: " << _specialClassNum << endl;
    }

};

int main() {
    int specialStudentNum = 11;

    Student st("����", 3, 5, 200, specialStudentNum);

    st.Info();

    cout << endl;

    specialStudentNum = 8;

    st.Info();




    return 0;
}