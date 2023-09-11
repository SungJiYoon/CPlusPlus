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
    SoccerSon(string name, float speed, float weight, float height, string skill) {
        cout << "SoccerSon ���ڸ� �޴� ������" << endl;
        _name = name;
        _speed = speed;
        _weight = weight;
        _height = height;
        _skill = skill;
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

};



int main() {
    // ��ü�� ����� ���� �ڵ����� ȣ��Ǿ����� ����Լ��� �ֽ��ϴ�.
    // ��ü�� �� �Լ��� ȣ��Ǿ������ ������ ��ü�� ������ �˴ϴ�.
    // �� �Լ��� ������(Constructor)��� �մϴ�.
    // ��ü�� �޸𸮿� �����ϰ� �ִ�, �Ҵ�Ǿ� �ִ� ���¸� instence��� �Ѵ�.
    // �޸𸮿� �Ҵ��Ҷ� �����ڰ� �۵��ȴ�.
    // �����ڰ� ȣ��Ǿ������ ������ ��ü�ν� �޸𸮿� �Ҵ�Ǵ� ���̴�.
    SoccerSon player;   // �⺻ �����ڰ� ȣ��


    player.SetName("�����");
    player.SetSpeed(10.3f);
    player.SetWeight(83.0f);
    player.SetHeight(183.0f);
    player.SetSkill("OverHeadKick");

    cout << "�̸�: " << player.GetName() << endl;
    cout << "100���� �޸���: " << player.GetSpeed() << endl;
    cout << "������: " << player.GetWeight() << endl;
    cout << "����: " << player.GetHeight() << endl;
    cout << "�ֿ佺ų: " << player.GetSkill() << endl;

    cout << endl;

    SoccerSon player2("�����2", 9.9f, 85.0f, 189.0f, "����");   // ���ڸ� �޴� �����ڰ� ȣ��

    cout << "�̸�: " << player2.GetName() << endl;
    cout << "100���� �޸���: " << player2.GetSpeed() << endl;
    cout << "������: " << player2.GetWeight() << endl;
    cout << "����: " << player2.GetHeight() << endl;
    cout << "�ֿ佺ų: " << player2.GetSkill() << endl;



    return 0;
}