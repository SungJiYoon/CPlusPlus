#include <iostream>
using namespace std;

// 복사생성자를 반드시 만들어야 하는 경우가 있습니다.
// 아래의 경우가 복사생성자를 반드시 만들어야 하는 경우입니다.

class DynamicArray {
private:
    int* _parr;
    int _size;

public:
    DynamicArray(int size)
        : _size(size)
    {
        cout << "DynamicArray(int size) 생성자" << endl;
        _parr = new int[size];
    }

    // 복사 생성자
    DynamicArray(DynamicArray& ref)
        : _size(ref._size)
    {
        cout << "DynamicArray의 복사생성자" << endl;
        _parr = new int[_size];   // 인자로 들어온 ref의 사이즈와 동일한 동적배열을 만든다.

        // 동일한 값 넣어준다.
        for (int i = 0; i < _size; i++) {
            _parr[i] = ref._parr[i];
        }
    }


    ~DynamicArray() {
        cout << "DynamicArray() 소멸자" << endl;
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

    DynamicArray array(10); // 생성자로 초기화

    for (int i = 0; i < array.GetSize(); i++) {
        array.SetIndex(i, i);
    }

    cout << "array 객체 출력" << endl;
    for (int i = 0; i < array.GetSize(); i++) {
        cout << "array[" << i << "] = " << array.GetIndex(i) << endl;
    }

    // DynamicArray array2 = array; // 복사생성자
    DynamicArray array2(array); // 복사생성자(얕은 카피 shallow copy) : 값 그대로 복사, 컴파일러가 자동으로 만들어주는 복사생성자
                                // array의 동적배열을 서로 똑같이 사용하게 된다(parr)
                                // 원래 저장공간을 따로 가지고 있어야한다.
    // 처음 array의 동적배열이 소멸자를 호출하면서 사라진다.
    // 두 번째 array2의 동적배열은 array의 똑같은 저장공간을 갖고 있었으므로 소멸자를 호출할 때 이미 동적배열이 날라간 상태라서 에러가 발생한다.
    // 그래서 array2는 저장공간을 따로 가지고 있되, array 동적배열 안의 값만 그대로 복사되어야 한다.
    // 그러기 위해서 복사생성자를 만들어줘야한다.

    

    cout << endl;
    cout << "array2 객체 출력" << endl;
    for (int i = 0; i < array2.GetSize(); i++) {
        cout << "array2[" << i << "] = " << array2.GetIndex(i) << endl;
    }

    // 깊은 카피 deep copy : 우리가 만든 복사생성자 됐는지 확인
    array.SetIndex(5, 1000);

    // 주소값 바꼈는지 확인
    cout << "array 객체 출력" << endl;
    for (int i = 0; i < array.GetSize(); i++) {
        cout << "array[" << i << "] = " << array.GetIndex(i) << endl;
    }

    cout << endl;
    cout << "array2 객체 출력" << endl;
    for (int i = 0; i < array2.GetSize(); i++) {
        cout << "array2[" << i << "] = " << array2.GetIndex(i) << endl;
    }


    return 0;
}