#include <iostream>
#include <cstring> // memset
using namespace std;

bool arr[51][51];
bool visited[51][51];
int move_x[4] = { 1, -1, 0, 0 };
int move_y[4] = { 0, 0, 1, -1 };
int M, N, K;

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int next_x = x + move_x[i];		// x 방향 이동
		int next_y = y + move_y[i];		// y 방향 이동
		if (next_x >= 0 && next_x < M) {		// 배추밭 범위 체크
			if (next_y >= 0 && next_y < N) {
				if (arr[next_x][next_y] && !visited[next_x][next_y])
					dfs(next_x, next_y);	// 다른 배추로 이동
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			arr[x][y] = true;
		}

		int ans = 0;
		for (int i = 0; i <= M; i++) {
			for (int j = 0; j <= N; j++) {
				if (arr[i][j] && !visited[i][j]) {
					dfs(i, j);	// 배추가 심어져있는데, 방문안했으면 dfs시작
					ans++;		// 지렁이 + 1
				}
			}
		}
		cout << ans << endl;
		memset(visited, false, sizeof(visited));
		memset(arr, false, sizeof(arr));
	}
	return 0;
}