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

    // 출력은 되는데 에러나는 이유는
    // array 는 10과 1000번지를 가지고 있다치고,
    // array2는 20과 2000번지를 가지고 있다하면
    // array = array2를 했을 때 둘다 10과 1000번지를 가지게 된다.
    // 그럼 1000번지의 메모리는 array, array2 둘다 가르키게 된다.
    // array에 의해 1000번지에 있던 메모리가 소멸되면
    // array2에서 에러가 나게된다. -> 1000번지에 있던 메모리가 없기 때문
    // 그래서 이런 경우엔 대입 연산자 오버로딩을 해줘야 한다.
    array = array2;   // 대입 연산


    array.Info();
    array2.Info();

    return 0;
}