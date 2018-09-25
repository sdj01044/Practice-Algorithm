#include <iostream>
#include <queue>
#include <string.h>		// memset
using namespace std;

bool arr[1001][1001];
bool visited[1001];
queue<int> q;

void dfs(int n, int v) {
	visited[v] = true;
	cout << v << " ";
	for (int i = 1; i <= n; i++) {
		if(arr[v][i] && !visited[i])
			dfs(n, i);
	}
}

void bfs(int n, int v) {
	visited[v] = true;
	q.push(v);

	int now;
	while (!q.empty()) {
		now = q.front();
		cout << now << " ";
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (arr[now][i] && !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = arr[b][a] = true;
	}

	dfs(N, V);
	cout << endl;
	memset(visited, false, N+1);
	bfs(N, V);
	return 0;
}