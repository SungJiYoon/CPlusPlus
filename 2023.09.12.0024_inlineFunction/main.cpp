#include <iostream>
#include <string>
#include "Building.h"

using namespace std;


// C++���� �»������� C����� ���������� ������� ������ �Ǿ����ϴ�.
// �����(.h, �������), ������(.cpp)�� ����� �����ϵ��� �Ǿ��ֽ��ϴ�.
// Ŭ���� ���ο��� �Լ��� ������ �ϴ� ���(�����ΰ� �ִ� ���) �����Ϸ��� 
// ���� �ٸ��� �޾Ƶ帳�ϴ�.
// inline �Լ��� ����� �޶�� ��û���� �޾Ƶ帳�ϴ�.
// �ݵ�� inline�Լ��� ����� ���� ���� �ƴմϴ�.
// �����Ϸ��� �Ǵ��ؼ� inline �Լ��� ����� ������ inline�Լ���
// ó���ϰ� ���ϴ� ��쿡�� �Լ��� ����ϴ�.

int main()
{
	Building starTower("��ŸŸ��", 112300.23f, 23);

	cout << "������: " << starTower.GetName() << endl;
	cout << "��ü����: " << starTower.GetArea() << endl;
	cout << "��ü����: " << starTower.GetMaxFloor() << endl;

	starTower.CheckFloor(-1);

	cout << "CheckAllFloor" << endl;
	starTower.CheckAllFloor();

	return 0;
}