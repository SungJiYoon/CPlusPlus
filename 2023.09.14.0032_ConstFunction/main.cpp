#include <iostream>
#include <string>

using namespace std;

class Fruit {
private:
    string _name;        // ���ϸ�
    float _weight;       // ����
    float _brixDegree;   // �絵

public:
    Fruit(string name, float weight, float brixDegree)
        : _name(name), _weight(weight), _brixDegree(brixDegree)
    {

    }

    string GetName() const {   // const�� ����Լ� (��������� ���� �������� �ʴ� �Լ�)
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
        cout << "���ϸ�: " << _name << endl;
        cout << "����: " << _weight << "g" << endl;
        cout << "�絵: " << _brixDegree << "%" << endl;
        cout << endl;
    }
};

// ��ü�� ���ڷ� �����Ҷ�.
// ���������� ������ �մϴ�.
// const�� ���ڸ� ���� �޴� ��쿡��
// �Լ��ȿ��� ���ڷ� ���޹��� ��ü�� ���� �������� �ʰڴٴ� �ǹ��Դϴ�.
// const�� ���ڸ� �����ϴ� ��� �Լ��ȿ��� ����Լ��� ȣ���ϴ� ��쿡��
// const�� ����Լ��� ȣ�� �� �� �ֽ��ϴ�.
void PrintFruit(const Fruit& ref) {
    cout << "���ϸ�: " << ref.GetName() << endl;
    cout << "����: " << ref.GetWeight() << "g" << endl;
    cout << "�絵: " << ref.GetBrixDegree() << "%" << endl;
    cout << endl;

    //ref.SetName("ȣ��");   // ���������� ���ڸ� ���� �ް� �Ǵ� ��쿡
                             // ���޹��� ������ ��ü�� ���� �Ǽ��� �����Ҽ��� �ֽ��ϴ�.
}

int main() {
    Fruit fruitArray[3] = {
       {"�ٳ���", 0.3f, 80.0f},
       {"���", 0.8f, 83.0f},
       {"����", 0.2f, 78.0f}
    };

    int length = sizeof(fruitArray) / sizeof(Fruit);

    for (int i = 0; i < length; i++) {
        PrintFruit(fruitArray[i]);
    }

    cout << "������" << endl;
    for (int i = 0; i < length; i++) {
        fruitArray[i].ShowInfo();
    }

    // ��ü������ 3�� �Ӽ�
    // 1. ĸ��ȭ : Ŭ������ ������ Ÿ���� ����� ��� / ���м�(����������) / �߻�ȭ
    // 2. ��� :
    //          ���������� �δ°�
    //          �θ� : base Ŭ���� / �ڽ� : derived Ŭ����(������ Ŭ����)
    //          is a ���� / has a ����
    //          ������ 2������ ���� : �����ֱ⸦ �����ϴ°� Composition(�ռ�) / �����ֱ⸦ ���������ʴ°� Aggregation(����)
    //          ����� �ϴ� ��� : Generalization �Ϲ�ȭ / Specialization Ư��ȭ
    //          �Ϲ�ȭ : �������� ����� ������ �̾Ƽ� �߷��� ������ �װɷ� Ŭ������ �����, ����� �������� ������� Ŭ������ ������ ����� ��Ű�� ��
    //          Ư��ȭ : Ŭ���� �ϳ��� �������� Ÿ���� ���� �Ǿ �б⹮�� ����ؼ� Ŭ������ ���������, ��ȿ������ �Ǿ��.
    //                   �̷��� ����� ������. Ŭ���� �ȿ��� Ư���� ��쿡 �ش��ϴ� �͵��� �̾Ƴ���.
    //                   �Ʊ� ó�� Ŭ�������� �Ϲ����� ������ �д�.
    //                   ���� ���������� ����� �����ش�. (ó�� Ŭ������ �̾Ƴ´� Ŭ��������)
    // 3. ������

    return 0;
}