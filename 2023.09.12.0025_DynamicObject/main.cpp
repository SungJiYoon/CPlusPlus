#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


int main() {
	int a;

	// C������ malloc(�޸��Ҵ�), calloc(�޸��Ҵ�), realoc(�޸����Ҵ�), free(�޸� �ݳ�)
	int* pa = (int*)malloc(sizeof(int));
	         //int �ּҰ����� ����
						//sizeof(int)��ŭ �Ҵ�
	*pa = 200;

	cout << "pa = " << pa << endl;
	cout << "*pa = " << *pa << endl;

	free(pa);   // �����޸� �ݳ�ó��
	pa = NULL;   // ������ �ּҰ��� �ݳ�ó���� �Ŀ��� NULL�� �ʱ�ȭ �ϴ� ���� �����մϴ�.
	free(pa);

	// C++������ new �����ڸ� ����ؼ� �����޸� ������ �Ҵ��մϴ�.
	cout << "\nC++ new" << endl;
	pa = new int;   // new �����ڸ� ���ؼ� int�� ���������� �������� �Ҵ�޾���.

	*pa = 342323;

	cout << "pa = " << pa << endl;
	cout << "*pa = " << *pa << endl;

	delete pa;   // C++������ �����޸� ������ �ݳ�ó���Ҷ� delete �����ڸ� ����մϴ�.

	return 0;
}