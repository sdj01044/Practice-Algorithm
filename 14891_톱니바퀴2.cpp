#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int arr[4][8];	// N극 : 0, S극 : 1
bool visited[4];

void rotate(int n, int d) {
	if (d == 1) {	// 1 : 시계방향
		int tmp = arr[n][7];
		for (int i = 7; i > 0; i--) {
			arr[n][i] = arr[n][i - 1];
		}
		arr[n][0] = tmp;
	}
	else {			// -1 : 반시계 방향
		int tmp = arr[n][0];
		for (int i = 0; i < 7; i++) {
			arr[n][i] = arr[n][i + 1];
		}
		arr[n][7] = tmp;
	}
}

void dfs(int n, int d) {
	visited[n] = true;
	int left = arr[n][6];
	int right = arr[n][2];
	rotate(n, d);
	if (n + 1 < 4) {
		if (right != arr[n + 1][6] && !visited[n + 1]){
			dfs(n + 1, d*(-1));
		}
	}

	if (n - 1 >= 0) {
		if (left != arr[n - 1][2] && !visited[n - 1]) {
			dfs(n - 1, d*(-1));
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int num, dir;
		cin >> num >> dir;
		dfs(num - 1, dir);
		memset(visited, false, sizeof(visited));
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (arr[i][0] == 1) {
			//int score = pow(2, i);
			ans += pow(2, i);
		}
	}
	cout << ans << '\n';
	return 0;
}