#include <iostream>

using namespace std;

// 축구게임에서 필요한 손흥민의 데이타를 추상화 하시고
// 클래스로 캡슐화한 후에 객체를 만들고 데이타를 채우고
// 출력해보세요..

enum Position {
	Coalkeeper,
	Defenders,
	Forward
};

class Son {
private:
	int uniformNumber; // 등번호
	string playerName; // 선수이름
	string clubName;   // 구단명
	Position position; // 포지션

public:
	void SetUniformNumber(int value) {
		uniformNumber = value;
	}

	int GetUniformNumber() {
		return uniformNumber;
	}

	void SetPlayerName(string value) {
		playerName = value;
	}

	string GetPlayerName() {
		return playerName;
	}

	void SetClubName(string value) {
		clubName = value;
	}

	string GetClubName() {
		return clubName;
	}

	void SetPosition(Position value) {
		position = value;
	}

	Position GetPosition() {
		return position;
	}
};

int main() {

	Son a;
	a.SetPosition(Forward);
	cout << a.GetPosition() << endl;

	return 0;
}