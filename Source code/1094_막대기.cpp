#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	int sticks[60] = {64, };
	int sum = 64, idx = 0;
	int count = 0;				// �ٿ����� ����� ��

	while (sum > x) {
		int half = sticks[idx] / 2;

		if (sum - sticks[idx] + half >= x) {	// ���� �ϳ� ������ ��
			sum = sum - sticks[idx] + half;
			idx++;
			sticks[idx] = half;
		}	
		else {									// ���� �ȹ����� ��
			sticks[idx + 1] = half;
			sticks[idx + 2] = half;
			idx += 2;
			count++;
		}
	}

	cout << count+1 << endl;
	return 0;
}