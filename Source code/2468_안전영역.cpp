#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 100
struct point {
	int x, y;
};
int arr[MAX][MAX];
bool visited[MAX][MAX];
int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };
int N;
queue<point> q;

void bfs(int rain, point s) {
	visited[s.x][s.y] = true;
	q.push(s);
	point now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + d_x[i];
			int ny = now.y + d_y[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (arr[nx][ny] > rain && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}//end for
	}//end while
}

int main() {
	cin >> N;
	int rain_max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (rain_max < arr[i][j])
				rain_max = arr[i][j];
		}
	}

	int ans = 0;
	for (int k = 0; k < rain_max; k++) {
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] > k && !visited[i][j]) {
					bfs(k, { i, j });
					tmp++;
				}
			}
		}
		memset(visited, false, sizeof(visited));
		if (ans < tmp)
			ans = tmp;
	}
	cout << ans << endl;
	return 0;
}