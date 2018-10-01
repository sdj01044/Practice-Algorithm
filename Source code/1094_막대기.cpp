#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;

	int sticks[60] = {64, };
	int sum = 64, idx = 0;
	int count = 0;				// 붙여야할 막대기 수

	while (sum > x) {
		int half = sticks[idx] / 2;

		if (sum - sticks[idx] + half >= x) {	// 절반 하나 버렸을 때
			sum = sum - sticks[idx] + half;
			idx++;
			sticks[idx] = half;
		}	
		else {									// 절반 안버렸을 때
			sticks[idx + 1] = half;
			sticks[idx + 2] = half;
			idx += 2;
			count++;
		}
	}

	cout << count+1 << endl;
	return 0;
}