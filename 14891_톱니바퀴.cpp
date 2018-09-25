#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int arr[4][8];
bool visited[4];

void rotate(int num, int dir) {
	if (dir == 1) {
		int tmp = arr[num][7];
		for (int i = 7; i > 0; i--) {
			arr[num][i] = arr[num][i - 1];
		}
		arr[num][0] = tmp;
	}
	else {
		int tmp = arr[num][0];
		for (int i = 0; i < 7; i++) {
			arr[num][i] = arr[num][i + 1];
		}
		arr[num][7] = tmp;
	}
}

void move(int num, int dir) {	// dfs
	visited[num] = true;
	int left = arr[num][6];
	int right = arr[num][2];
	rotate(num, dir);
	if (num + 1 < 4) {
		if (right != arr[num + 1][6] && !visited[num + 1]) {
			move(num + 1, dir*(-1));
		}
	}

	if (num - 1 >= 0) {
		if (left != arr[num - 1][2] && !visited[num - 1]) {
			move(num - 1, dir*(-1));
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
		move(num - 1, dir);
		memset(visited, false, sizeof(visited));
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (arr[i][0] == 1) {
			int score = pow(2, i);
			ans += score;
		}
	}
	cout << ans << endl;
	return 0;
}