#include <iostream>
#include <cstring>
using namespace std;

struct point {
	int x, y;
};
int arr[300][300];
int arr_tmp[300][300];
bool visited[300][300];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int N, M;

bool melting_ice() {
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
					if (arr[nx][ny] == 0 && arr[i][j]>0 && arr_tmp[i][j] > 0)
						arr_tmp[i][j]--;
				}
			}//end for
			if (arr[i][j] != 0) {
				flag = true;
			}
		}//end for
	}//end for
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = arr_tmp[i][j];
		}
	}
	return flag;
}

void dfs(point s) {
	visited[s.x][s.y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = s.x + dx[i];
		int ny = s.y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
			if (arr[nx][ny] != 0 && !visited[nx][ny]) {
				dfs({ nx, ny });
			}
		}
	}//end for
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			arr_tmp[i][j] = arr[i][j];
		}
	}
	int ans = 0;
	while (true) {
		ans++;
		bool flag = false;
		if (!melting_ice()) {
			cout << 0 << '\n';
			return 0;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] != 0 && !visited[i][j]) {
					if (flag) {
						cout << ans << '\n';
						return 0;
					}
					dfs({ i, j });
					flag = true;
				}
			}
		}
		flag = false;
		memset(visited, false, sizeof(visited));
	}//end while
	return 0;
}