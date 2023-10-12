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

    // array = array2 를 하면 카피를 하게끔 하고 싶다.
    // 그러기 위해서는 일단 array에 있던 동적 메모리 공간을 없앤다.
    // array2에 맞춰서 동적 메모리 공간을 다시 만든다.
    // array2에 10과 1000번지 주소값을 가지고 있다 치면
    // array에 10을 복사하고, 주소번지는 3000번(다른주소)로 하고,
    // array2의 1000번지에 있던 값을 그대로 복사한다.
    DynamicArray& operator=(DynamicArray& rightValue) {
        cout << "DynamicArray& operator=(DynamicArray& rightValue)" << endl;
        delete[] _parr;   // 기존의 동적배열을 삭제

        _size = rightValue._size;

        _parr = new int[_size];   // rightValue와 동일한 사이즈의 동적배열을 생성

        // rightValue의 동적배열에 저장된 값을 복사
        for (int i = 0; i < _size; i++) {
            _parr[i] = rightValue._parr[i];
        }

        // 대입 연산자를 쭉 이어서 쓸 수 있기 때문에
        // 지금 이 함수를 호출한 애를 리턴한다.
        return *this;
    }

    // 배열 첨자연산자를 연산자 오버로딩(객체를 배열형식으로 사용할 수 있음)
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

    array3.operator[](2) = 4000; //<= 설명

    cout << "array3 = ";
    array3.Info();

    cout << "array2 = ";
    array2.Info();

    cout << "array = ";
    array.Info();

    return 0;
}