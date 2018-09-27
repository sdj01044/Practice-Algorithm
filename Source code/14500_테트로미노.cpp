#include <iostream>
#include <cstring>
using namespace std;

#define MAX 500
struct point {
	int x, y;
};
int arr[MAX][MAX];
bool visited[MAX][MAX];
int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };
int N, M, ans = 0;

void another(point s, int d) {
	int sum = arr[s.x][s.y];
	//visited[s.x][s.y] = true;
	switch (d)
	{
	case 0: {	// ㅏ
		int d_idx = 2;
		for (int i = 0; i < 3; i++) {
			int n_x = s.x + d_x[d_idx];
			int n_y = s.y + d_y[d_idx];
			if (n_x >= 0 && n_y >= 0 && n_x < N && n_y < M) {
				sum += arr[n_x][n_y];
				//visited[n_x][n_y] = true;
			}
			else
				return;
			d_idx = (d_idx+1)%4;
		}
		break;
	}case 1: {	// ㅓ
		for (int i = 1; i < 4; i++) {
			int n_x = s.x + d_x[i];
			int n_y = s.y + d_y[i];
			if (n_x >= 0 && n_y >= 0 && n_x < N && n_y < M)
				sum += arr[n_x][n_y];
			else
				return;
		}
		break;
	}case 2: {	// ㅗ
		int d_idx = 3;
		for (int i = 0; i < 3; i++) {
			int n_x = s.x + d_x[d_idx];
			int n_y = s.y + d_y[d_idx];
			if (n_x >= 0 && n_y >= 0 && n_x < N && n_y < M)
				sum += arr[n_x][n_y];
			else
				return;
			d_idx = (d_idx + 1) % 4;
		}
		break;
	}case 3: {	// ㅜ
		for (int i = 0; i < 3; i++) {
			int n_x = s.x + d_x[i];
			int n_y = s.y + d_y[i];
			if (n_x >= 0 && n_y >= 0 && n_x < N && n_y < M)
				sum += arr[n_x][n_y];
			else
				return;
		}
		break;
	}
	}//end switch
	if (sum > ans)
		ans = sum;
}

void dfs(point s, int depth, int sum) {	// ㅡ, ㅁ, ㄱ, ㄹ
	if (depth > 4) {
		if (ans < sum)
			ans = sum;
		return;
	}
	visited[s.x][s.y] = true;
	sum += arr[s.x][s.y];

	for (int i = 0; i < 4; i++) {
		int n_x = s.x + d_x[i];
		int n_y = s.y + d_y[i];
		if (n_x >= 0 && n_y >= 0 && n_x < N && n_y < M) {
			if (!visited[n_x][n_y]) {
				dfs({ n_x,n_y }, depth + 1, sum);
				visited[n_x][n_y] = false;	// 다시 false해야 함
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dfs({ i, j }, 1, 0);
			memset(visited, false, sizeof(visited));
			for (int k = 0; k < 4; k++) {
				another({ i, j }, k);
			}
		}
	}
	cout << ans << endl;
	return 0;
}