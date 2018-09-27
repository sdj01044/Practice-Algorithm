#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct point {
	int x, y, time;
};
int arr[50][50];
bool visited[50][50];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int T, N, M, R, C, L;

int bfs(int r, int c, int time) {
	int ans = 1;
	visited[r][c] = true;
	queue<point> q;
	q.push({ r,c, time });

	point now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		if (now.time == L)
			break;

		switch (arr[now.x][now.y]) {
		case 1: {
			for (int i = 0; i < 4; i++) {
				int nr = now.x + dx[i];
				int nc = now.y + dy[i];
				if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
					if (arr[nr][nc] != 0 && !visited[nr][nc]) {
						if (i == 0 && arr[nr][nc] != 2 && arr[nr][nc] != 4 && arr[nr][nc] != 5) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
						if (i == 1 && arr[nr][nc] != 2 && arr[nr][nc] != 6 && arr[nr][nc] != 7) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
						if (i == 2 && arr[nr][nc] != 3 && arr[nr][nc] != 5 && arr[nr][nc] != 6) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
						if (i == 3 && arr[nr][nc] != 3 && arr[nr][nc] != 4 && arr[nr][nc] != 7) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
					}
				}
			}
			break;
		}case 2: {
			for (int i = 2; i < 4; i++) {
				int nr = now.x + dx[i];
				int nc = now.y;
				if (nr >= 0 && nr < N) {
					if (arr[nr][nc] != 0 && !visited[nr][nc] && arr[nr][nc] != 3) {
						if (i == 2 && arr[nr][nc] != 5 && arr[nr][nc] != 6) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
						if (i == 3 && arr[nr][nc] != 4 && arr[nr][nc] != 7) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
					}
				}
			}
			break;
		}case 3: {
			for (int i = 0; i < 2; i++) {
				int nr = now.x;
				int nc = now.y + dy[i];
				if (nc >= 0 && nc < M) {
					if (arr[nr][nc] != 0 && !visited[nr][nc] && arr[nr][nc] != 2) {
						if (i == 0 && arr[nr][nc] != 4 && arr[nr][nc] != 5) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
						if (i == 1 && arr[nr][nc] != 6 && arr[nr][nc] != 7) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
					}
				}
			}
			break;
		}case 5: {
			for (int i = 0; i < 3; i += 2) {
				int nr = now.x + dx[i];
				int nc = now.y + dy[i];
				if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
					if (arr[nr][nc] != 0 && !visited[nr][nc]) {
						if (i == 0 && arr[nr][nc] != 2 && arr[nr][nc] != 4 && arr[nr][nc] != 5) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
						if (i == 2 && arr[nr][nc] != 3 && arr[nr][nc] != 5 && arr[nr][nc] != 6) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
					}
				}
			}
			break;
		}case 4: {
			for (int i = 0; i < 4; i += 3) {
				int nr = now.x + dx[i];
				int nc = now.y + dy[i];
				if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
					if (arr[nr][nc] != 0 && !visited[nr][nc]) {
						if (i == 0 && arr[nr][nc] != 2 && arr[nr][nc] != 4 && arr[nr][nc] != 5) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
						if (i == 3 && arr[nr][nc] != 3 && arr[nr][nc] != 4 && arr[nr][nc] != 7) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
					}
				}
			}
			break;
		}case 6: {
			for (int i = 1; i < 3; i++) {
				int nr = now.x + dx[i];
				int nc = now.y + dy[i];
				if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
					if (arr[nr][nc] != 0 && !visited[nr][nc]) {
						if (i == 1 && arr[nr][nc] != 2 && arr[nr][nc] != 6 && arr[nr][nc] != 7) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
						if (i == 2 && arr[nr][nc] != 3 && arr[nr][nc] != 5 && arr[nr][nc] != 6) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
					}
				}
			}
			break;
		}case 7: {
			for (int i = 1; i < 4; i += 2) {
				int nr = now.x + dx[i];
				int nc = now.y + dy[i];
				if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
					if (arr[nr][nc] != 0 && !visited[nr][nc]) {
						if (i == 1 && arr[nr][nc] != 2 && arr[nr][nc] != 6 && arr[nr][nc] != 7) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
						if (i == 3 && arr[nr][nc] != 3 && arr[nr][nc] != 4 && arr[nr][nc] != 7) {
							visited[nr][nc] = true;	ans++;
							q.push({ nr, nc, now.time + 1 });
						}
					}
				}
			}
			break;
		}
		}//end switch
	}//end while
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
			}
		}
		cout << "#" << t << " " << bfs(R, C, 1) << '\n';
		memset(visited, false, sizeof(visited));
	}
	return 0;
}