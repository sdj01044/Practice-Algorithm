#include <iostream>
using namespace std;

#define MAX 20
char arr[MAX][MAX];
bool alphabet[26];
int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };
int R, C, ans = 0;

void dfs(int x, int y, int depth) {
	int cur_idx = arr[x][y] - 65;
	alphabet[cur_idx] = true;
	
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		int n_x = x + d_x[i];
		int n_y = y + d_y[i];
		if (n_x >= 0 && n_y >= 0 && n_x < R && n_y < C) {
			int next_idx = arr[n_x][n_y] - 65;
			if (!alphabet[next_idx]) {
				dfs(n_x, n_y, depth + 1);
				flag = true;
			}
		}
	}
	if (!flag) {
		if (ans < depth)
			ans = depth;
	}
	alphabet[cur_idx] = false;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0, 1);
	cout << ans << endl;
	return 0;
}