#include <iostream>
using namespace std;

#define MAX 101
bool apple[MAX][MAX];	// 맵에서 사과의 위치
bool map[MAX][MAX];		// 뱀이 이동하는 맵
int snake[MAX][2];		// 뱀 몸의 좌표
int move_t[MAX];		// move time
char move_d[MAX];		// move direct
int N, K, L;

int d_y[4] = { 1, 0, -1, 0};	// 이런 순서로 해야
int d_x[4] = { 0, 1, 0, -1};	// 방향전환을 쉽게 할 수 있다.

int move() {
	int time = 0, m_idx = 0, snake_len = 1;
	int cur_d = 0, cur_x = 1, cur_y = 1;	// 현재 방향과 머리위치
	map[1][1] = true;	// 처음 뱀의 위치
	snake[snake_len][0] = cur_x;	snake[snake_len][1] = cur_y;

	for (time;; time++) {
		if (time == move_t[m_idx]) {
			if (move_d[m_idx] == 'L') {	// 왼쪽 회전
				cur_d--;
				if (cur_d < 0)
					cur_d = 3;
			}
			else {						// 오른쪽 회전
				cur_d = (cur_d + 1) % 4;
			}
			m_idx++;
		}
		int next_x, next_y;		// 시간에 따른 한칸 이동
		next_x = cur_x + d_x[cur_d];
		next_y = cur_y + d_y[cur_d];
		if (map[next_x][next_y]) {		// 몸 부딪힘 여부
			break;
		}
		else if (next_x > N || next_x < 1) {	// 벽 부딪힘 여부
			break;
		}
		else if (next_y > N || next_y < 1) {
			break;
		}

		cur_x = next_x; cur_y = next_y;		// 머리 다음칸으로 이동
		if (apple[next_x][next_y]) {	// 사과 먹으면 몸 증가
			snake_len++;
			snake[snake_len][0] = next_x;
			snake[snake_len][1] = next_y;
			apple[next_x][next_y] = false;
		}
		else {							// 사과 없는 경우 몸 한칸씩 이동
			for (int i = snake_len; i > 0; i--) {
				snake[0][0] = snake[i][0];
				snake[0][1] = snake[i][1];
				snake[i][0] = next_x;
				snake[i][1] = next_y;
				next_x = snake[0][0];
				next_y = snake[0][1];
 			}
			map[next_x][next_y] = false;	// 마지막 뱀몸통 false
		}
		map[cur_x][cur_y] = true;
	}
	return ++time;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		apple[r][c] = true;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int X;	char C;
		cin >> X >> C;
		move_t[i] = X;
		move_d[i] = C;
	}
	cout << move() << endl;
	return 0;
}