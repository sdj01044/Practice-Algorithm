#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int k, y, round = 1;
	cin >> k >> y;

	while (N > 1) {
		int next_k = k / 2 + k % 2;		// k�� ���� ��ȣ
		int next_y = y / 2 + y % 2;		// y�� ���� ��ȣ

		if (next_k == next_y)	// k�� y�� ���
			break;
		else {					// ��� ����
			N = N / 2 + N % 2;	// ���� ������ N
			k = next_k;
			y = next_y;
			round++;
		}
	}

	cout << round << endl;

	return 0;
}