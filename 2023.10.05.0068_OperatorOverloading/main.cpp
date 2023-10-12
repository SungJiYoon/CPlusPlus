#include <iostream>

using namespace std;

class DynamicArray {
private:
    int* _parr;
    int _size;

public:
    DynamicArray(int size)
        : _size(size)
    {
        cout << "���ڸ� �޴� ������" << endl;
        _parr = new int[_size];
    }

    ~DynamicArray() {
        delete[] _parr;
    }

    int GetSize() {
        return _size;
    }


    int GetIndex(int index) {
        return _parr[index];
    }

    void SetIndex(int index, int value) {
        _parr[index] = value;
    }

    void Info() {
        for (int i = 0; i < _size; i++) {
            cout << _parr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    DynamicArray array(20);
    DynamicArray array2(10);
    DynamicArray array3(30);

    for (int i = 0; i < array2.GetSize(); i++) {
        array2.SetIndex(i, i);

    }

    // ����� �Ǵµ� �������� ������
    // array �� 10�� 1000������ ������ �ִ�ġ��,
    // array2�� 20�� 2000������ ������ �ִ��ϸ�
    // array = array2�� ���� �� �Ѵ� 10�� 1000������ ������ �ȴ�.
    // �׷� 1000������ �޸𸮴� array, array2 �Ѵ� ����Ű�� �ȴ�.
    // array�� ���� 1000������ �ִ� �޸𸮰� �Ҹ�Ǹ�
    // array2���� ������ ���Եȴ�. -> 1000������ �ִ� �޸𸮰� ���� ����
    // �׷��� �̷� ��쿣 ���� ������ �����ε��� ����� �Ѵ�.
    array = array2;   // ���� ����


    array.Info();
    array2.Info();

    return 0;
}