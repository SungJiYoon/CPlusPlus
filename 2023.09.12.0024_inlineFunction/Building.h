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

	inline void CheckAllFloor(); // inline 키워드를 사용하면 해당 함수를
								 // inline함수로 만들어달라는 요청으로 받아드립니다.
};

// inline함수로 요청하려면 구현코드가 헤더파일에 같이 있어야 합니다.
inline void Building::CheckAllFloor() {
	std::cout << std::endl;
	std::cout << "빌딩의 모든 시스템을 체크합니다." << std::endl;

	for (int i = -1; i < _maxFloor; i++)
	{
		CheckFloor(i);
	}
}