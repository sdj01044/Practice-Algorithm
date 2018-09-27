#include <iostream>
#include <queue>
using namespace std;

struct point {
	int x, y, time;
};
#define MAX 1000
int arr[MAX][MAX];			// 0 : 안익음, 1 : 익음, -1 : 빈것
bool visited[MAX][MAX];
int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };
int N, M;
queue<point> q;

int bfs() {
	point now;
	while (!q.empty()) {
		now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = now.x + d_x[i];
			int next_y = now.y + d_y[i];
			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
				if (arr[next_x][next_y] == 0 && !visited[next_x][next_y]) {
					q.push({ next_x, next_y, now.time + 1 });
					visited[next_x][next_y] = true;
				}
			}
		}//end for
	}//end while
	return now.time;
}

int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				q.push({ i, j, 0 });
				visited[i][j] = true;
			}
			else if(arr[i][j] == -1){
				visited[i][j] = true;
			}
		}
	}

	int ans = bfs();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}