#include <iostream>
#include <queue>
using namespace std;

#define MAX 101
struct point
{
	int x, y, time;
};
int N, M;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int d_x[4] = {0, 0, 1, -1};
int d_y[4] = { 1, -1, 0, 0 };
queue<point> q;

void bfs(point s) {
	visited[s.x][s.y] = true;
	q.push(s);

	while (!q.empty()) {
		point now = q.front();
		q.pop();

		if (now.x == N && now.y == M) {
			cout << now.time << endl;
			return;
		}

		for (int i = 0; i < 4; i ++) {
			int next_x = now.x + d_x[i];
			int next_y = now.y + d_y[i];

			if (next_x <= N && next_y <= M && next_x > 0 && next_y > 0) {
				if (arr[next_x][next_y] == 1 && !visited[next_x][next_y]) {
					visited[next_x][next_y] = true;
					q.push({ next_x, next_y, now.time + 1 });
				}
			}
		}//end for
	}//end while
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	point start;
	start.x = 1;	start.y = 1;	start.time = 1;
	bfs(start);
	return 0;
}