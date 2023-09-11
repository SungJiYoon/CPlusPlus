#include <iostream>
#include <string>

using namespace std;

// �౸���ӿ��� �ʿ��� ������� ����Ÿ�� �߻�ȭ �Ͻð�
// Ŭ������ ĸ��ȭ�� �Ŀ� ��ü�� ����� ����Ÿ�� ä���
// ����غ�����..

class SoccerSon {
private:
    // �Ϲݺ����� ��������� �����ϱ� ���� ��������տ� ���λ縦 ���̴� ���� �����ϴ�.
    string _name; // �������, attribute, property, field
    float _speed;
    float _weight;
    float _height;
    string _skill;

public:
    // ������ // Ŭ������� ������ �̸��� �Լ�, ���ϰ��� �����ϴ�.
    // �ƹ� ���ڵ� ���� �ʴ� �����ڸ� �⺻ �����ڶ�� �մϴ�.
    // �����ڸ� �ȸ���� �����ڴ� �ݵ�� �ʿ��ϱ� ������
    // �����Ϸ��� �⺻�����ڸ� �ڵ����� ����� �ݴϴ�.
    // �������� ��Ȱ��
    // ��ü�� �����ɶ� ���� �۾��� �����ڿ��� �Ͻø�˴ϴ�.
    // ���� ��������� �ʱ�ȭ�ϴ� �۾��� �մϴ�.

    SoccerSon() {
        cout << "SoccerSon �⺻ ������" << endl;
    }


    // ���ڸ� �޴� ������
    SoccerSon(string name, float speed, float weight, float height, string skill) 
        :_name(name), _speed(speed), _weight(weight), _height(height), _skill(skill)
    {
        cout << "SoccerSon ���ڸ� �޴� ������" << endl;
        //_name = name;
        //_speed = speed;
        //_weight = weight;
        //_height = height;
        //_skill = skill;
    }

    // ���ڸ� �޴� ������
    SoccerSon(string name) 
        :_name(name), _speed(0.0f), _weight(0.0f), _height(0.0f), _skill("����")
    {
        cout << "SoccreSon ���ڸ� �ϳ� �޴� ������" << endl;
        //_name = name;
        //_speed = 0.0f;
        //_weight = 0.0f;
        //_height = 0.0f;
        //_skill = "����";
    }

    void SetName(string value) { // ����Լ�, �޼ҵ�, behaviour
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

    void Info() {
        cout << "�̸�: " << _name << endl;
        cout << "100���� �޸���: " << GetSpeed() << endl;
        cout << "������: " << GetWeight() << endl;
        cout << "����: " << GetHeight() << endl;
        cout << "�ֿ佺ų: " << GetSkill() << endl;

    }

};



int main() {
    // ��ü�� ����� ���� �ڵ����� ȣ��Ǿ����� ����Լ��� �ֽ��ϴ�.
    // ��ü�� �� �Լ��� ȣ��Ǿ������ ������ ��ü�� ������ �˴ϴ�.
    // �� �Լ��� ������(Constructor)��� �մϴ�.
    SoccerSon player;   // �⺻ �����ڰ� ȣ��


    player.SetName("�����");
    player.SetSpeed(10.3f);
    player.SetWeight(83.0f);
    player.SetHeight(183.0f);
    player.SetSkill("OverHeadKick");

    player.Info();


    // ���ڸ� �޴� �����ڸ� �ϳ��� ����� �����Ϸ��� �⺻�����ڸ� �ڵ����� ���������� �ʽ��ϴ�.
    // �⺻�����ڰ� ���ٴ� ���� ���ڸ� ���� �ʰ� ��ü�� �����ϴ� ���� ������� �ʰڴٴ� �ǹ��Դϴ�.
    // �⺻������ ����� ������ �ʰ�� ������ ���Դϴ�.




    cout << endl;

    SoccerSon player2("�����2", 9.9f, 85.0f, 189.0f, "����");   // ���ڸ� �޴� �����ڰ� ȣ��
    player2.Info();


    cout << endl;

    SoccerSon player3("�����3");
    player3.Info();


    return 0;
}