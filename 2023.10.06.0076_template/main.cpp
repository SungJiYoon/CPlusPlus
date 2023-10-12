#include <iostream>
#include <string>

using namespace std;


struct Student {
    string name;
    int age;
    int grade;
};

// 템플릿 클래스
template <typename T>
class DynamicArray {
private:
    T* _parr;
    int _size;

public:
    DynamicArray(int size)
        : _size(size)
    {
        cout << "인자를 받는 생성자" << endl;
        _parr = new T[_size];
    }

    ~DynamicArray() {
        delete[] _parr;
    }

    DynamicArray& operator=(DynamicArray& rightValue) {
        cout << "DynamicArray& operator=(DynamicArray& rightValue)" << endl;
        delete[] _parr;   // 기존의 동적배열을 삭제

        _size = rightValue._size;

        _parr = new T[_size];   // rightValue와 동일한 사이즈의 동적배열을 생성

        // rightValue의 동적배열에 저장된 값을 복사
        for (int i = 0; i < _size; i++) {
            _parr[i] = rightValue._parr[i];
        }

        return *this;
    }


    // 배열 첨자연산자를 연산자 오버로딩
    T& operator[](int index) {
        return _parr[index];
    }

    int GetSize() {
        return _size;
    }



};


template <typename T>
ostream& operator<<(ostream& o, DynamicArray<T>& right) {
    for (int i = 0; i < right.GetSize(); i++) {
        o << right[i] << ", ";
    }

    return o;
}


// 템플릿 특수화
template<>
ostream& operator<<(ostream& o, DynamicArray<Student>& ref) {
    for (int i = 0; i < ref.GetSize(); i++) {
        o << "나이: " << ref[i].age << ", 학년: " << ref[i].grade << ", 이름: " << ref[i].name << endl;
    }

    return o;
}






int main() {
    DynamicArray<int> array(20);

    DynamicArray<float> farray(10);

    DynamicArray<double> darray(10);


    for (int i = 0; i < array.GetSize(); i++) {
        array[i] = i;
    }

    for (int i = 0; i < farray.GetSize(); i++) {
        farray[i] = i * 1.2f;
    }

    for (int i = 0; i < darray.GetSize(); i++) {
        darray[i] = i * 3.23;
    }

    cout << array << endl;

    cout << farray << endl;

    cout << darray << endl;


    DynamicArray<Student> sArray(10);

    for (int i = 0; i < sArray.GetSize(); i++) {
        sArray[i].name = "monster";
        sArray[i].age = i;
        sArray[i].grade = i % 3 + 1;
    }

    cout << sArray << endl;





    return 0;
}