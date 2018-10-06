#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct State {
	int i;
	int j;
	int time;
};
char map[1000][1000];
bool visited[1000][1000];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
queue<State> fire;
queue<State> sang;

void bfs(int H, int W) {
	State now_fire, now_sang;
	while (!sang.empty()) {
		now_sang = sang.front();
		sang.pop();

		if (now_sang.i == 0 || now_sang.j == 0 || now_sang.i == H-1 || now_sang.j == W-1) {
			cout << now_sang.time+1 << endl;
			return;
		}

		// 불 이동 (큐에 들어있는거 다 한번씩 이동시킴)
		int fire_count = fire.size();
		while (fire_count--) {
			now_fire = fire.front();
			if (now_fire.time != now_sang.time) {
				break;
			}
			fire.pop();
			
			for (int k = 0; k < 4; k++) {
				int fnext_i = now_fire.i + dy[k];
				int fnext_j = now_fire.j + dx[k];
				if (fnext_i >= 0 && fnext_j >= 0 && fnext_i < H && fnext_j < W) {
					if (map[fnext_i][fnext_j] != '#' && map[fnext_i][fnext_j] != '*') {
						fire.push({ fnext_i, fnext_j, now_fire.time + 1 });
						visited[fnext_i][fnext_j] = true;
						map[fnext_i][fnext_j] = '*';
					}
				}
			}//end for
		}//end while

		// 상근이 이동
		for (int k = 0; k<4; k++) {
			int snext_i = now_sang.i + dy[k];
			int snext_j = now_sang.j + dx[k];
			if (map[snext_i][snext_j] != '#' && map[snext_i][snext_j] != '*') {
				if (!visited[snext_i][snext_j]) {
					sang.push({ snext_i, snext_j, now_sang.time + 1 });
					visited[snext_i][snext_j] = true;
				}
			}
		}//end for
	}//end while
	cout << "IMPOSSIBLE" << endl;
}

int main() {
	int T;	cin >> T;
	while (T--) {
		int W, H;		// 너비, 높이
		cin >> W >> H;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				if (map[i][j] == '*') {
					fire.push({ i, j, 0 });
					visited[i][j] = true;
				}
				else if (map[i][j] == '@') {
					sang.push({ i, j, 0 });
					visited[i][j] = true;
				}
				else if (map[i][j] == '#')
					visited[i][j] = true;
			}
		}
		bfs(H, W);

		memset(visited, false, sizeof(visited));
		while(!fire.empty())fire.pop();
		while (!sang.empty())sang.pop();
	}//end while
	return 0;
}