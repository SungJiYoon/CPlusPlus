#pragma once
class Global {
private:
	static int Score;	// �����������
	static int Score1;
	static int Score2;

	//������������� private�� �����ؼ� �ٷ������ϴ°� ����
	//��������Լ��� ���ؼ� �����ϰԲ� �ϴ°� �� ����
	//�̷��� �Լ��� ���� �����ϰ� �ϸ� ������ ã�µ� �� �����ϴ�
public:
	static void SetScore(int value) {
		Score = value;
	}

	static int GetScore() {
		return Score;
	}

	static void SetScore1(int value) {
		Score1 = value;
	}

	static int GetScore1() {
		return Score1;
	}

	static void SetScore2(int value) {
		Score2 = value;
	}

	static int GetScore2() {
		return Score2;
	}

};
