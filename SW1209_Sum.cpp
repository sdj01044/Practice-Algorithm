#include <iostream>
using namespace std;

int arr[100][100];

int main() {
	for (int t = 0; t < 10; t++) {
		int T;
		cin >> T;

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
			}
		}
		
		// 행 비교
		int max_row = 0;
		for (int i = 0; i < 100; i++) {
			int sum = 0;
			for (int j = 0; j < 100; j++)
				sum += arr[i][j];
			if (sum > max_row)
				max_row = sum;
		}

		// 열 비교
		int max_col = 0;
		for (int j = 0; j < 100; j++) {
			int sum = 0;
			for (int i = 0; i < 100; i++)
				sum += arr[i][j];
			if (sum > max_col)
				max_col = sum;
		}

		// 대각선1 비교
		int max_dia1 = 0;
		for (int i = 0; i < 100; i++) {
			max_dia1 += arr[i][i];
		}

		// 대각선2 비교
		int max_dia2 = 0;
		for (int i = 0; i < 100; i++) {
			max_dia2 += arr[i][99 - i];
		}

		int m1 = max_row > max_col ? max_row : max_col;
		int m2 = max_dia1 > max_dia2 ? max_dia1 : max_dia2;
		int ans = m1 > m2 ? m1 : m2;
		cout << "#" << T << " " << ans << endl;
	}

	return 0;
}