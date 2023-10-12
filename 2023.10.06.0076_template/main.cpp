#include <iostream>
#include <string>

using namespace std;


struct Student {
    string name;
    int age;
    int grade;
};

// ���ø� Ŭ����
template <typename T>
class DynamicArray {
private:
    T* _parr;
    int _size;

public:
    DynamicArray(int size)
        : _size(size)
    {
        cout << "���ڸ� �޴� ������" << endl;
        _parr = new T[_size];
    }

    ~DynamicArray() {
        delete[] _parr;
    }

    DynamicArray& operator=(DynamicArray& rightValue) {
        cout << "DynamicArray& operator=(DynamicArray& rightValue)" << endl;
        delete[] _parr;   // ������ �����迭�� ����

        _size = rightValue._size;

        _parr = new T[_size];   // rightValue�� ������ �������� �����迭�� ����

        // rightValue�� �����迭�� ����� ���� ����
        for (int i = 0; i < _size; i++) {
            _parr[i] = rightValue._parr[i];
        }

        return *this;
    }


    // �迭 ÷�ڿ����ڸ� ������ �����ε�
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


// ���ø� Ư��ȭ
template<>
ostream& operator<<(ostream& o, DynamicArray<Student>& ref) {
    for (int i = 0; i < ref.GetSize(); i++) {
        o << "����: " << ref[i].age << ", �г�: " << ref[i].grade << ", �̸�: " << ref[i].name << endl;
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