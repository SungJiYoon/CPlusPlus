#include <iostream>

using namespace std;

int main() {
	int money = 0;
	cout << "�뵷 �ݾ� �Է��ϼ���: ";
	cin >> money;
	
	// Ȯ���� ������ �տ� �δ°� ������
	if (money <= 60000 && money > 40000) {
		cout << "�߱���" << endl;
	}
	else if (money > 100000) { // ���� ���ǹ�
		cout << "PC��" << endl;
	}
	else if (money <= 100000 && money > 80000) {
		cout << "�籸��" << endl;
	}
	else if (money <= 80000 && money > 60000) {
		cout << "�뷡��" << endl;
	}
	else if (money <= 40000 && money > 20000) {
		cout << "ī��" << endl;
	}
	else { // ���� ����
		cout << "����" << endl;
	}

	return 0;
}