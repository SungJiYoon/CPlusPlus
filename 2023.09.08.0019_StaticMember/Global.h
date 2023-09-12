#pragma once
class Global {
private:
	static int Score;	// 정적멤버변수
	static int Score1;
	static int Score2;

	//정적멤버변수는 private로 선언해서 바로접근하는걸 막음
	//정적멤버함수를 통해서 접근하게끔 하는게 더 좋다
	//이렇게 함수를 통해 접근하게 하면 오류를 찾는데 더 용이하다
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
