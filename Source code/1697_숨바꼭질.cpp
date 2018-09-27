#include <iostream>
#include <queue>
using namespace std;

#define MAX 200000
bool visited[MAX];
int time[MAX];
queue<int> q;

void bfs(int n, int k) {
	visited[n] = true;
	q.push(n);

	int now;
	while (!q.empty()) {
		now = q.front();
		if (now == k) {
			cout << time[now] << endl;
			break;
		}
		q.pop();

		if (now-1 >=0 && !visited[now - 1]) {
			q.push(now - 1);
			time[now - 1] = time[now] + 1;
			visited[now - 1] = true;
		}
		if (now+1 < MAX && !visited[now + 1]) {
			q.push(now + 1);
			time[now + 1] = time[now] + 1;
			visited[now + 1] = true;
		}
		if (now*2 < MAX && !visited[now * 2]) {
			q.push(now * 2);
			time[now * 2] = time[now] + 1;
			visited[now * 2] = true;
		}
	}
}

int main() {
	int N, K;
	cin >> N >> K;
	bfs(N, K);
	return 0;
}