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
		int next_x = x + move_x[i];		// x ���� �̵�
		int next_y = y + move_y[i];		// y ���� �̵�
		if (next_x >= 0 && next_x < M) {		// ���߹� ���� üũ
			if (next_y >= 0 && next_y < N) {
				if (arr[next_x][next_y] && !visited[next_x][next_y])
					dfs(next_x, next_y);	// �ٸ� ���߷� �̵�
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
					dfs(i, j);	// ���߰� �ɾ����ִµ�, �湮�������� dfs����
					ans++;		// ������ + 1
				}
			}
		}
		cout << ans << endl;
		memset(visited, false, sizeof(visited));
		memset(arr, false, sizeof(arr));
	}
	return 0;
}