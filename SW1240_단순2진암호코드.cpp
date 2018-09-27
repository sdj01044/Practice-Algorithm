#include <iostream>
using namespace std;

int arr[50][100];

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;
		int start_i = 0, start_j = 0;
		bool flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%c",&arr[i][j]);
				if (!flag && arr[i][j] & 1) {
					start_i = i;	start_j = j;
					flag = true;
				}
			}
		}

		for (int i = start_i; i < N; i++) {
			for (int j = start_j; j < (start_j + 55); j++) {

			}
		}
	}

	return 0;
}