#include <iostream>
#include <queue>
using namespace std;

#define MAX 10
struct point {
	int x, y;
};
char arr[MAX][MAX];		// . ��ĭ / # �� / O ���� / R,B ����
bool visited_r[MAX][MAX];
bool visited_b[MAX][MAX];
int d_x[4] = { 0, 0, 1, -1 };
int d_y[4] = { 1, -1, 0, 0 };
int N, M;
queue<point> q_r, q_b;

bool move_blue() {
	int size = q_b.size();
	for (int i = 0; i < size; i++) {
		point now = q_r.front();
		q_b.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + d_x[i];
			int ny = now.y + d_y[i];
			int cnt = 0;
			while (true) {
				if (arr[nx][ny] == '.') {
					cnt++;
				}
				else if (arr[nx][ny] == '#') {
					break;
				}
				else if (arr[nx][ny] == 'O') {
					q_b.push({ nx, ny });
					return true;
				}
				nx += d_x[i];
				ny += d_y[i];
			}//end while
			nx = now.x + d_x[i] * cnt;
			ny = now.y + d_y[i] * cnt;
			visited_b[nx][ny] = true;
			q_b.push({ nx, ny });
		}//end for
	}//end for
	return false;
}

bool move_red() {
	int size = q_r.size();
	for (int i = 0; i < size; i++) {
		point now = q_r.front();
		q_r.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + d_x[i];
			int ny = now.y + d_y[i];
			int cnt = 0;
			while (true) {
				if (arr[nx][ny] == '.') {
					cnt++;
				}
				else if (arr[nx][ny] == '#') {
					break;
				}
				else if (arr[nx][ny] == 'O') {
					q_r.push({ nx, ny });
					return true;
				}
				nx += d_x[i];
				ny += d_y[i];
			}//end while
			nx = now.x + d_x[i] * cnt;
			ny = now.y + d_y[i] * cnt;
			visited_r[nx][ny] = true;
			q_r.push({ nx, ny });
		}//end for
	}//end for
	return false;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				visited_r[i][j] = true;
				q_r.push({ i, j });
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				visited_b[i][j] = true;
				q_b.push({ i, j });
				arr[i][j] = '.';
			}
		}
	}
	int ans = 0;
	while (true) {
		ans++;
		if (q_r.size() == 0 || ans > 10) {		// ���������� ���̻� ������ �� ����
			cout <<"a: "<< -1 << endl;
			return 0;
		}

		if (move_red()) {			// ���������� ���� ���
			if (move_blue()) {		// �Ķ������� ���� ���� ���
				cout <<"b: "<< -1 << endl;
				return 0;
			}
			cout <<"c: "<< ans << endl;
			return 0;
		}
	}//end while
	return 0;
}