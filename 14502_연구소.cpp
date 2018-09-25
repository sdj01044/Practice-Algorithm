#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 9
struct point
{
	int x, y;
};
int arr_ori[MAX][MAX];
int arr[MAX][MAX];
bool visited[MAX][MAX];
int d_x[4] = { 1, -1, 0, 0 };
int d_y[4] = { 0, 0, 1, -1 };
int N, M, max_safe = 0;
queue<point> q_virus, q_spread;

void count_safe() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0)			// 0 count
				cnt++;
		}
	}
	if (max_safe < cnt)
		max_safe = cnt;
}

void virus(point s) {		// bfs
	q_spread.push(s);
	while (!q_spread.empty()) {
		s = q_spread.front();
		q_spread.pop();

		for (int i = 0; i < 4; i++) {
			point next_s;
			next_s.x = s.x + d_x[i];
			next_s.y = s.y + d_y[i];
			
			if (next_s.x >= 0 && next_s.y >= 0 && next_s.x < N && next_s.y < M) {
				if (arr[next_s.x][next_s.y] == 0) {
					q_spread.push(next_s);
					arr[next_s.x][next_s.y] = 2;
				}
			}
		}//end for
	}//end while
}

void wall(point start, int depth) {	// dfs
	arr_ori[start.x][start.y] = 1;
	visited[start.x][start.y] = true;

	if (depth == 3) {		// 벽이 3개 만들어진 경우
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				arr[i][j] = arr_ori[i][j];
			}
		}

		queue<point> q_tmp = q_virus;
		while (!q_tmp.empty()) {
			point tmp = q_tmp.front();
			virus(tmp);			// 바이러스 퍼트리기
			q_tmp.pop();
		}
		count_safe();	// safe존 개수 세기, arr 복원
		visited[start.x][start.y] = false;
		arr_ori[start.x][start.y] = 0;
		return;
	}
	else {		// 벽이 아직 3개 안된 경우
		for (int i = start.x; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr_ori[i][j] == 0 && !visited[i][j]) {
					point next;
					next.x = i;	next.y = j;
					wall(next, depth + 1);
				}
			}
		}
	}
	arr_ori[start.x][start.y] = 0;
	visited[start.x][start.y] = false;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr_ori[i][j];
			arr[i][j] = arr_ori[i][j];
			if (arr_ori[i][j] == 2) {
				point a;
				a.x = i;	a.y = j;
				q_virus.push(a);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr_ori[i][j] == 0) {
				point a;
				a.x = i;	a.y = j;
				wall(a, 1);
			}
		}
	}
	cout << max_safe << endl;
	return 0;
}