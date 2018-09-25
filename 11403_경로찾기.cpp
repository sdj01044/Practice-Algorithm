#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 100
int arr[MAX][MAX];
int ans[MAX][MAX];
bool visited[MAX];
int N;
queue<int> q;

void dfs(int s) {
	for (int i = 0; i < N; i++) {
		if (arr[s][i] && !visited[i]) {
			visited[i] = true;
			dfs(i);
		}
	}
}

void bfs(int s) {
	q.push(s);
	int now = 0;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = 0; i < N; i++) {
			if (arr[now][i] && !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {	// 방향있는 그래프
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];		// i에서 j로 가는 경우
		}
	}
	for (int i = 0; i < N; i++) {
		//dfs(i);
		bfs(i);
		for (int j = 0; j < N; j++) {
			if (visited[j])
				ans[i][j] = 1;
		}
		memset(visited, false, sizeof(visited));
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}