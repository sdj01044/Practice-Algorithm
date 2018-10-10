/* 연결 요소(Connected Component) : 연결된 최대 그래프 */
#include <iostream>
#include <cstring>
using namespace std;

bool arr[1001][1001];
bool visited[1001];

void dfs(int N, int i) {
	visited[i] = true;

	for (int next = 1; next <= N; next++) {
		if (arr[i][next] && !visited[next])
			dfs(N, next);
	}
}

int main() {
	int N, M;	// 정점 개수, 간선 개수
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;	cin >> u >> v;
		arr[u][v] = arr[v][u] = true;
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(N, i);
			count++;
		}
	}
	cout << count << endl;
}