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
        cout << "인자를 받는 생성자" << endl;
        _parr = new int[_size];
    }

    ~DynamicArray() {
        delete[] _parr;
    }

    DynamicArray& operator=(DynamicArray& rightValue) {
        cout << "DynamicArray& operator=(DynamicArray& rightValue)" << endl;
        delete[] _parr;   // 기존의 동적배열을 삭제

        _size = rightValue._size;

        _parr = new int[_size];   // rightValue와 동일한 사이즈의 동적배열을 생성

        // rightValue의 동적배열에 저장된 값을 복사
        for (int i = 0; i < _size; i++) {
            _parr[i] = rightValue._parr[i];
        }

        return *this;
    }

    // 배열 첨자연산자를 연산자 오버로딩
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


    array3 = array = array2;   // 대입 연산
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