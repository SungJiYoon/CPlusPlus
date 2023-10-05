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

    DynamicArray& operator=(DynamicArray& rightValue) {
        cout << "DynamicArray& operator=(DynamicArray& rightValue)" << endl;
        delete[] _parr;   // ������ �����迭�� ����

        _size = rightValue._size;

        _parr = new int[_size];   // rightValue�� ������ �������� �����迭�� ����

        // rightValue�� �����迭�� ����� ���� ����
        for (int i = 0; i < _size; i++) {
            _parr[i] = rightValue._parr[i];
        }

        return *this;
    }

    // �迭 ÷�ڿ����ڸ� ������ �����ε�
    int& operator[](int index) {
        return _parr[index];
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
        //array2.SetIndex(i, i);
        array2[i] = i;
    }


    array3 = array = array2;   // ���� ����
    //array3.operator=(array.operator=(array2));


    array.Info();
    array2.Info();
    array3.Info();

    cout << endl;
    array2[2] = 1000;
    array3[2] = 4000;

    cout << "array3 = ";
    array3.Info();

    cout << "array2 = ";
    array2.Info();

    cout << "array = ";
    array.Info();





    return 0;
}