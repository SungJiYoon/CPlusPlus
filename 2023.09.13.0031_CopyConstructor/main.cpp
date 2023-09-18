#include <iostream>
using namespace std;

// ��������ڸ� �ݵ�� ������ �ϴ� ��찡 �ֽ��ϴ�.
// �Ʒ��� ��찡 ��������ڸ� �ݵ�� ������ �ϴ� ����Դϴ�.

class DynamicArray {
private:
    int* _parr;
    int _size;

public:
    DynamicArray(int size)
        : _size(size)
    {
        cout << "DynamicArray(int size) ������" << endl;
        _parr = new int[size];
    }

    // ���� ������
    DynamicArray(DynamicArray& ref)
        : _size(ref._size)
    {
        cout << "DynamicArray�� ���������" << endl;
        _parr = new int[_size];   // ���ڷ� ���� ref�� ������� ������ �����迭�� �����.

        // ������ �� �־��ش�.
        for (int i = 0; i < _size; i++) {
            _parr[i] = ref._parr[i];
        }
    }


    ~DynamicArray() {
        cout << "DynamicArray() �Ҹ���" << endl;
        delete[] _parr;
    }

    void SetIndex(int index, int value) {
        _parr[index] = value;
    }

    int GetIndex(int index) {
        return _parr[index];
    }

    int GetSize() {
        return _size;
    }
};


int main() {

    DynamicArray array(10); // �����ڷ� �ʱ�ȭ

    for (int i = 0; i < array.GetSize(); i++) {
        array.SetIndex(i, i);
    }

    cout << "array ��ü ���" << endl;
    for (int i = 0; i < array.GetSize(); i++) {
        cout << "array[" << i << "] = " << array.GetIndex(i) << endl;
    }

    // DynamicArray array2 = array; // ���������
    DynamicArray array2(array); // ���������(���� ī�� shallow copy) : �� �״�� ����, �����Ϸ��� �ڵ����� ������ִ� ���������
                                // array�� �����迭�� ���� �Ȱ��� ����ϰ� �ȴ�(parr)
                                // ���� ��������� ���� ������ �־���Ѵ�.
    // ó�� array�� �����迭�� �Ҹ��ڸ� ȣ���ϸ鼭 �������.
    // �� ��° array2�� �����迭�� array�� �Ȱ��� ��������� ���� �־����Ƿ� �Ҹ��ڸ� ȣ���� �� �̹� �����迭�� ���� ���¶� ������ �߻��Ѵ�.
    // �׷��� array2�� ��������� ���� ������ �ֵ�, array �����迭 ���� ���� �״�� ����Ǿ�� �Ѵ�.
    // �׷��� ���ؼ� ��������ڸ� ���������Ѵ�.

    

    cout << endl;
    cout << "array2 ��ü ���" << endl;
    for (int i = 0; i < array2.GetSize(); i++) {
        cout << "array2[" << i << "] = " << array2.GetIndex(i) << endl;
    }

    // ���� ī�� deep copy : �츮�� ���� ��������� �ƴ��� Ȯ��
    array.SetIndex(5, 1000);

    // �ּҰ� �ٲ����� Ȯ��
    cout << "array ��ü ���" << endl;
    for (int i = 0; i < array.GetSize(); i++) {
        cout << "array[" << i << "] = " << array.GetIndex(i) << endl;
    }

    cout << endl;
    cout << "array2 ��ü ���" << endl;
    for (int i = 0; i < array2.GetSize(); i++) {
        cout << "array2[" << i << "] = " << array2.GetIndex(i) << endl;
    }


    return 0;
}