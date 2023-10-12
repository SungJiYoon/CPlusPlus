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

    // �̵������� (�ӽ������� ������ٰ� �������� temp(������ ����)�� �״�� �ޱ� ����)
    DynamicArray(DynamicArray&& rref) {
        _parr = rref._parr; // temp2�� temp�� 4000������ �ű��.
        rref._parr = NULL; // temp�� 4000������ NULL�� �ȴ�. NULL�̴ϱ� �Ҹ��ڰ� ȣ����� �ʴ´�. ���ٰ� �����ϱ� ����.
                           // �׷� 4000������ �޸� ������ temp2�� ����Ű�� �ȴ�.
                           // �� �� temp�� �������.
                           // ���� temp2�� array3�� ������ �Ͼ�ǵ� temp2�� �ӽ������� ��������ٰ� ����� �ִ�.
                           // �׷��� temp2�� �����޸𸮰����� array3�� �̵���Ų��. => DynamicArray& operator=(DynamicArray&& rref)
        _size = rref._size;

        // temp�� �����ϰ� array3�� ������ �ٽ� ����� �ϴ� ���ŷο� ���� �̵������ڸ� ����� �޸𸮰����� �������� �ʰ� �̵��ϴ� ������ �ִ�.
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

    // �̹��� temp2�� �����޸� ������ �̰���Ų��.
    DynamicArray& operator=(DynamicArray&& rref) {
        delete[] _parr; // array3�� ������ �ִ� ���� �޸� ���� ����

        _parr = rref._parr;
        rref._parr = NULL; // temp2�� �޸𸮰����� NULL�� �Ѵ�.

        _size = rref._size;

        return *this;
    }

    // DynamicArray + �����ڿ����ε� �Լ��� ����� �����ؼ� ����غ�����.
    DynamicArray operator+(DynamicArray& rightValue) {
        DynamicArray temp(_size + rightValue._size);   // �ӽ� ��ü ����

        for (int i = 0; i < _size; i++) {
            temp[i] = (*this)[i]; // �迭 ���� ������ �����ε��߱� ����
        }

        for (int i = 0; i < rightValue._size; i++) {
            temp[i + _size] = rightValue[i];
        }

        return temp;
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

    friend ostream& operator<<(ostream& o, DynamicArray& right);
};


// ����ڰ� ���� Ŭ���� ��ü�� �������� �����ʿ� ���̴� ��쿡��
// �����ڿ� ���ʿ� ���̴� ��ü�� �ҽ��� ������ �� ���� ���(cout ���� �Ұ�)
// �Ϲ��Լ��� ���ؼ� ������ �����ε��� �ϸ� �˴ϴ�.
// �Ϲ��Լ��� Ŭ������ ģ���Լ��� ����ϸ� ģ���Լ��� Ŭ������ private ������ ���� �� �� �ֽ��ϴ�.
ostream& operator<<(ostream& o, DynamicArray& right) {
    for (int i = 0; i < right._size; i++) {
        o << right[i] << ", ";
    }

    return o;
}

// �̵������� ��ü���� �帧�� ���ڸ�
// array + array2�� �� �� temp�� �����޸𸮰����� temp2�� �̰���Ű��,
// temp2�� �����޸𸮰����� array3�� �̰���Ų��.
// ���� ������ ������� �ϴ� ������ ���ص� �Ǵ� ������ �ִ�.
int main() {
    DynamicArray array(20);
    DynamicArray array2(10);
    DynamicArray array3(30);

    for (int i = 0; i < array2.GetSize(); i++) {
        //array2.SetIndex(i, i);
        array2[i] = i;
    }


    for (int i = 0; i < array.GetSize(); i++) {
        array[i] = i * 2;
    }


    array3 = array + array2;

    //array3.Info();

    cout << array3;


    return 0;
}