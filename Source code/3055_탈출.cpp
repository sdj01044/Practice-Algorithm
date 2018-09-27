#include <iostream>
#include <queue>
using namespace std;

#define MAX 50
struct point {
	int x, y;
};
char arr[MAX][MAX];
int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };
int R, C;
queue<point> q_w, q_s;

void bfs_water() {
	int size = q_w.size();
	for (int i = 0; i < size; i++) {		// 한번에 1깊이씩 탐색
		point now = q_w.front();
		q_w.pop();
		for (int j = 0; j < 4; j++) {		// 4방향 이동
			int nx = now.x + d_x[j];
			int ny = now.y + d_y[j];
			if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
				if (arr[nx][ny] == '.') {
					arr[nx][ny] = '*';
					q_w.push({ nx, ny });
				}
			}
		}
	}
}

bool bfs_s() {
	int size = q_s.size();
	for (int i = 0; i < size; i++) {		// 한번에 1깊이씩 탐색
		point now = q_s.front();
		q_s.pop();
		for (int j = 0; j < 4; j++) {		// 4방향 이동
			int nx = now.x + d_x[j];
			int ny = now.y + d_y[j];
			if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
				if (arr[nx][ny] == 'D') {
					q_s.push({ nx, ny });
					return true;
				}
				if (arr[nx][ny] == '.') {
					q_s.push({ nx, ny });
					arr[nx][ny] = 'S';
				}
			}
		}
	}
	return false;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '*') {
				q_w.push({ i, j });
			}
			else if (arr[i][j] == 'S') {
				q_s.push({ i, j });
			}
		}
	}

	int ans = 0;
	while (true) {
		ans++;
		if (q_s.size() == 0) {
			cout << "KAKTUS" << endl;
			return 0;
		}

		bfs_water();
		if (bfs_s()) {
			cout << ans << endl;
			return 0;
		}
	}
	return 0;
}