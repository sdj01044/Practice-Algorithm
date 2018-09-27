#include <iostream>
using namespace std;

#define MAX 50
int N, M, ans = 0;
int room[MAX][MAX];
int d_r[4] = {-1, 0, 1, 0};		// 북, 동, 남, 서
int d_c[4] = {0, 1, 0, -1};		// 순서

bool cleaned[MAX][MAX];

void dfs(int s_r, int s_c, int d) {
	if (room[s_r][s_c] == 0) {
		ans++;
		room[s_r][s_c] = 2;	// 현재 위치 청소
	}
	int n_r, n_c;

	for (int i = 0; i < 4; i++) {
		int n_d = (d + 3) % 4;	// next d
		n_r = s_r + d_r[n_d];
		n_c = s_c + d_c[n_d];

		if (room[n_r][n_c] == 0) {	// 빈 방이면 청소
			dfs(n_r, n_c, n_d);
			return;
		}else {
			d = n_d;	// 방향 전환을 위해서
		}
	}

	// 여기까지 왔다면 사방이 벽이거나 청소 끝남
	n_r = s_r + d_r[(d + 2) % 4];
	n_c = s_c + d_c[(d + 2) % 4];
	if(room[n_r][n_c] != 1)
		dfs(n_r, n_c, d);	// 후진
}

int main() {
	cin >> N >> M;
	int s_r, s_c, d;	// d=0북, d=1동, d=2남, d=3서
	cin >> s_r >> s_c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> room[i][j];
		}
	}
	dfs(s_r, s_c, d);
	cout << ans << endl;
	return 0;
}