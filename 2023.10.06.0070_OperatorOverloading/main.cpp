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

    // 이동생성자 (임시적으로 만들었다가 없어지는 temp(오른쪽 참조)를 그대로 받기 위해)
    DynamicArray(DynamicArray&& rref) {
        _parr = rref._parr; // temp2에 temp의 4000번지를 옮긴다.
        rref._parr = NULL; // temp의 4000번지가 NULL이 된다. NULL이니까 소멸자가 호출되지 않는다. 없다고 생각하기 때문.
                           // 그럼 4000번지의 메모리 공간은 temp2를 가르키게 된다.
                           // 그 후 temp는 사라진다.
                           // 이제 temp2가 array3에 대입이 일어날건데 temp2도 임시적으로 만들어졌다가 사라질 애다.
                           // 그래서 temp2의 동적메모리공간을 array3로 이동시킨다. => DynamicArray& operator=(DynamicArray&& rref)
        _size = rref._size;

        // temp를 삭제하고 array3에 공간을 다시 만들고 하는 번거로움 없이 이동생성자를 만들면 메모리공간을 삭제하지 않고 이동하는 이점이 있다.
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

    // 이번엔 temp2의 동적메모리 공간을 이관시킨다.
    DynamicArray& operator=(DynamicArray&& rref) {
        delete[] _parr; // array3가 가지고 있던 동적 메모리 공간 삭제

        _parr = rref._parr;
        rref._parr = NULL; // temp2의 메모리공간을 NULL로 한다.

        _size = rref._size;

        return *this;
    }

    // DynamicArray + 연산자오버로딩 함수를 만들고 실행해서 출력해보세요.
    DynamicArray operator+(DynamicArray& rightValue) {
        DynamicArray temp(_size + rightValue._size);   // 임시 객체 생성

        for (int i = 0; i < _size; i++) {
            temp[i] = (*this)[i]; // 배열 참조 연산을 오버로딩했기 때문
        }

        for (int i = 0; i < rightValue._size; i++) {
            temp[i + _size] = rightValue[i];
        }

        return temp;
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

    friend ostream& operator<<(ostream& o, DynamicArray& right);
};


// 사용자가 만든 클래스 객체가 연산자의 오른쪽에 놓이는 경우에는
// 연산자에 왼쪽에 놓이는 객체의 소스를 수정할 수 없는 경우(cout 수정 불가)
// 일반함수를 통해서 연산자 오버로딩을 하면 됩니다.
// 일반함수를 클래스의 친구함수로 등록하면 친구함수는 클래스의 private 영역에 접근 할 수 있습니다.
ostream& operator<<(ostream& o, DynamicArray& right) {
    for (int i = 0; i < right._size; i++) {
        o << right[i] << ", ";
    }

    return o;
}

// 이동생성자 전체적인 흐름을 보자면
// array + array2를 할 때 temp의 동적메모리공간을 temp2로 이관시키고,
// temp2의 동적메모리공간을 array3로 이관시킨다.
// 굳이 지웠다 만들었다 하는 과정을 안해도 되는 이점이 있다.
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