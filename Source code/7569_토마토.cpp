#include <iostream>
#include <queue>
using namespace std;

#define MAX 100
struct point {
	int x, y, z, time;
};
int arr[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int d_x[6] = { 0, 0, 1, -1, 0, 0 };
int d_y[6] = { 1, -1, 0, 0, 0, 0 };
int d_z[6] = { 0, 0, 0, 0, 1, -1 };
int M, N, H;	// 가로, 세로, 높이
queue<point> q;

int bfs() {
	point now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int n_x = now.x + d_x[i];
			int n_y = now.y + d_y[i];
			int n_z = now.z + d_z[i];
			if (n_x >= 0 && n_y >= 0 && n_z >= 0 && n_x < H && n_y < N && n_z < M) {
				if (!visited[n_x][n_y][n_z] && arr[n_x][n_y][n_z] == 0) {
					visited[n_x][n_y][n_z] = true;
					q.push({ n_x, n_y, n_z, now.time + 1 });
				}
			}
		}//end for
	}//end while
	return now.time;
}

int main() {
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push({ i, j, k, 0 });
					visited[i][j][k] = true;
				}
				else if (arr[i][j][k] == -1)
					visited[i][j][k] = true;
			}
		}
	}

	int ans = bfs();
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (!visited[i][j][k]) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}