#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct point {
	int x, y, time;
};
char arr[50][50];
bool visited[50][50];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N, M;
queue<point> q;

int bfs(point s) {
	visited[s.x][s.y] = true;	
	q.push(s);

	point now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (arr[nx][ny] == 'L' && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx, ny, now.time + 1 });
				}
			}
		}//end for
	}//end while
	return now.time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'L' && !visited[i][j]) {
				int res = bfs({ i,j, 0 });
				if (res > ans)
					ans = res;
				memset(visited, false, sizeof(visited));
			}
		}
	}
	cout << ans << '\n';
	return 0;
}