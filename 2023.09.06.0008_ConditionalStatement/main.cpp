#include <iostream>

using namespace std;

int main() {
	int money = 0;
	cout << "용돈 금액 입력하세요: ";
	cin >> money;
	
	// 확률이 높은걸 앞에 두는게 유리함
	if (money <= 60000 && money > 40000) {
		cout << "중국집" << endl;
	}
	else if (money > 100000) { // 다중 조건문
		cout << "PC방" << endl;
	}
	else if (money <= 100000 && money > 80000) {
		cout << "당구장" << endl;
	}
	else if (money <= 80000 && money > 60000) {
		cout << "노래방" << endl;
	}
	else if (money <= 40000 && money > 20000) {
		cout << "카페" << endl;
	}
	else { // 생략 가능
		cout << "낮잠" << endl;
	}

	return 0;
}