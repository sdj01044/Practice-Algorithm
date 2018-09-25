#include <iostream>
using namespace std;

#define MAX 50
int N, M, ans = 0;
int room[MAX][MAX];
int d_r[4] = {-1, 0, 1, 0};		// ��, ��, ��, ��
int d_c[4] = {0, 1, 0, -1};		// ����

bool cleaned[MAX][MAX];

void dfs(int s_r, int s_c, int d) {
	if (room[s_r][s_c] == 0) {
		ans++;
		room[s_r][s_c] = 2;	// ���� ��ġ û��
	}
	int n_r, n_c;

	for (int i = 0; i < 4; i++) {
		int n_d = (d + 3) % 4;	// next d
		n_r = s_r + d_r[n_d];
		n_c = s_c + d_c[n_d];

		if (room[n_r][n_c] == 0) {	// �� ���̸� û��
			dfs(n_r, n_c, n_d);
			return;
		}else {
			d = n_d;	// ���� ��ȯ�� ���ؼ�
		}
	}

	// ������� �Դٸ� ����� ���̰ų� û�� ����
	n_r = s_r + d_r[(d + 2) % 4];
	n_c = s_c + d_c[(d + 2) % 4];
	if(room[n_r][n_c] != 1)
		dfs(n_r, n_c, d);	// ����
}

int main() {
	cin >> N >> M;
	int s_r, s_c, d;	// d=0��, d=1��, d=2��, d=3��
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