#include <iostream>
#include <queue>
using namespace std;

#define MAX 8
struct point {
	int x, y;
};
int arr[MAX][MAX];
int arr_tmp[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int N, M, _max = 0;

int bfs_virus() {	// ���̷��� ��Ʈ����, �������� ����
	queue<point> q;
	for (int i = 0; i < N; i++) {		// arr����, ���̷��� ��ġ ť�� �ֱ�
		for (int j = 0; j < M; j++) {
			arr_tmp[i][j] = arr[i][j];
			if (arr[i][j] == 2)
				q.push({ i, j });
		}
	}

	point now;
	while (!q.empty()) {	// ���̷��� ��Ʈ����
		now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (arr_tmp[nx][ny] == 0) {
					arr_tmp[nx][ny] = 2;
					q.push({ nx, ny });
				}
			}
		}//end for
	}//end while

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr_tmp[i][j] == 0)
				cnt++;
		}
	}
	return cnt;
}

void dfs(point s, int depth) {	// �� 3�� �����
	if (depth == 3) {
		arr[s.x][s.y] = 1;
		int res = bfs_virus();
		if (res > _max)
			_max = res;
		arr[s.x][s.y] = 0;
		return;
	}
	arr[s.x][s.y] = 1;
	visited[s.x][s.y] = true;
	for (int i = s.x; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0 && !visited[i][j]) {
				dfs({ i, j }, depth + 1);
			}
		}
	}
	arr[s.x][s.y] = 0;
	visited[s.x][s.y] = false;
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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(arr[i][j]==0)
				dfs({ i, j }, 1);
		}
	}
	cout << _max << '\n';
	return 0;
}