#include <iostream>

using namespace std;

// �౸���ӿ��� �ʿ��� ������� ����Ÿ�� �߻�ȭ �Ͻð�
// Ŭ������ ĸ��ȭ�� �Ŀ� ��ü�� ����� ����Ÿ�� ä���
// ����غ�����..

enum Position {
	Coalkeeper,
	Defenders,
	Forward
};

class Son {
private:
	int uniformNumber; // ���ȣ
	string playerName; // �����̸�
	string clubName;   // ���ܸ�
	Position position; // ������

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