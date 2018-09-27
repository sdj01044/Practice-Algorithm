#include <iostream>
#include <cstring>
using namespace std;

int mx[4] = { 0, 0, 1, -1 };
int my[4] = { 1, -1, 0, 0 };
char arr[17][17];
bool visited[17][17];
bool ans = false;

void dfs(int x, int y) {
	if (arr[y][x] == '3') {
		ans = true;
		return;
	}

	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int n_x = x + mx[i];
		int n_y = y + my[i];
		if (n_x < 17 && n_x > 0  && n_y < 17 && n_y > 0) {
			if (arr[n_y][n_x] != '1' && !visited[n_y][n_x]) {
				dfs(n_x, n_y);
				if (ans)	return;
			}
		}
	}
	return;
}

int main() {
	for (int t = 0; t < 1; t++) {
		int T, s_x, s_y;	cin >> T;

		for (int i = 1; i <= 16; i++) {
			char input[17];	cin >> input;
			for (int j = 1; j <= 16; j++) {
				arr[i][j] = input[j-1];
				if (arr[i][j] == '2'){
					s_x = j;	s_y = i;
				}
			}
		}

		dfs(s_x, s_y);
		cout << "#" << T << " " << (ans ? 1 : 0) << endl;
		memset(visited, false, sizeof(visited));
		ans = false;
	}
	return 0;
}