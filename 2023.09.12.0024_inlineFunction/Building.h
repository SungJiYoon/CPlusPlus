#pragma once
#include <iostream>
#include <string>


class Building {
private:
	std::string _name;
	float _area;
	int _maxFloor;

public:
	Building(std::string name, float area, int maxFloor);

	std::string GetName();

	float GetArea();

	int GetMaxFloor();

	void CheckFloor(int floor);

	inline void CheckAllFloor(); // inline Ű���带 ����ϸ� �ش� �Լ���
								 // inline�Լ��� �����޶�� ��û���� �޾Ƶ帳�ϴ�.
};

// inline�Լ��� ��û�Ϸ��� �����ڵ尡 ������Ͽ� ���� �־�� �մϴ�.
inline void Building::CheckAllFloor() {
	std::cout << std::endl;
	std::cout << "������ ��� �ý����� üũ�մϴ�." << std::endl;

	for (int i = -1; i < _maxFloor; i++)
	{
		CheckFloor(i);
	}
}