#include <iostream>
using namespace std;

int d[15][15 ];

void init() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			d[i][j] = 0;
		}
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int k, n;
		cin >> k >> n;

		for (int i = 0; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == 0)		// 0층 j호에는 j명이 산다.
					d[i][j] = j;
				else {			// i층 j호에는 i-1층의 1~j층까지 합한 인원이 산다.
					for (int m = 1; m <= j; m++)
						d[i][j] += d[i-1][m];
				}
			}
		}
		cout << d[k][n] << endl;
		init();
	}

	return 0;
}