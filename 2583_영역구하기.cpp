#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 100
struct point {
	int x, y;
};
bool arr[MAX][MAX];
int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };
int M, N, K;	// 세로, 가로, 사각형수
vector<int> v;
queue<point> q;

int bfs(point s) {
	int cnt = 1;
	arr[s.x][s.y] = true;
	q.push(s);

	point now;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_x = now.x + d_x[i];
			int n_y = now.y + d_y[i];
			if (n_x >= 0 && n_y >= 0 && n_x < M && n_y < N) {
				if (!arr[n_x][n_y]) {
					arr[n_x][n_y] = true;
					cnt++;
					q.push({ n_x, n_y });
				}
			}
		}//end for
	}//end while
	return cnt;
}

int main() {
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {		// 사각형 영역 표시하기
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int width = x2 - x1, height = y2 - y1;
		int start_x = x1, start_y = M - y2, k = 0;
		for (int h = height; h > 0; h--) {
			int j = 0;
			for (int w = width; w > 0; w--) {
				arr[start_y + k][start_x + j] = true;
				j++;
			}
			k++;
		}
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) {
				v.push_back(bfs({ i, j }));
				ans++;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << ans << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}