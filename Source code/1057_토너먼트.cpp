#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int k, y, round = 1;
	cin >> k >> y;

	while (N > 1) {
		int next_k = k / 2 + k % 2;		// k의 다음 번호
		int next_y = y / 2 + y % 2;		// y의 다음 번호

		if (next_k == next_y)	// k와 y가 대결
			break;
		else {					// 대결 안함
			N = N / 2 + N % 2;	// 다음 라운드의 N
			k = next_k;
			y = next_y;
			round++;
		}
	}

	cout << round << endl;

	return 0;
}