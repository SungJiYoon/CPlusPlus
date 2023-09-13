#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


int main() {
	int a;

	// C언어에서는 malloc(메모리할당), calloc(메모리할당), realoc(메모리재할당), free(메모리 반납)
	int* pa = (int*)malloc(sizeof(int));
	         //int 주소값으로 저장
						//sizeof(int)만큼 할당
	*pa = 200;

	cout << "pa = " << pa << endl;
	cout << "*pa = " << *pa << endl;

	free(pa);   // 동적메모리 반납처리
	pa = NULL;   // 변수의 주소값을 반납처리한 후에는 NULL로 초기화 하는 것이 안전합니다.
	free(pa);

	// C++에서는 new 연산자를 사용해서 동적메모리 공간을 할당합니다.
	cout << "\nC++ new" << endl;
	pa = new int;   // new 연산자를 통해서 int형 변수공간을 동적으로 할당받았음.

	*pa = 342323;

	cout << "pa = " << pa << endl;
	cout << "*pa = " << *pa << endl;

	delete pa;   // C++에서는 동적메모리 공간을 반납처리할때 delete 연산자를 사용합니다.

	return 0;
}