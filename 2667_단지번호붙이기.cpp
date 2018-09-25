#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 25
struct point {
	int x, y;
};
int arr[MAX][MAX];
bool visited[MAX][MAX];
int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };
int N, num_g = 0;	// ´ÜÁö¼ö
queue<point> q;
vector<int> v;

void bfs(point s) {
	int num_h = 1;
	num_g++;
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
				if (!visited[nx][ny] && arr[nx][ny] == 1) {
					num_h++;
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}//end for
	}//end while
	v.push_back(num_h);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && arr[i][j] == 1)
				bfs({ i, j });
		}
	}
	sort(v.begin(), v.end());
	cout << num_g << endl;
	for (int i = 0; i < num_g; i++) {
		cout << v[i] << endl;
	}
	return 0;
}