#include <iostream>
#include <queue>
using namespace std;

struct Floor {
	int cur;
	int cnt;
};

bool visited[1000001];
int F, S, G, U, D;

void bfs() {
	queue<Floor> q;
	q.push({S, 0});
	visited[S] = true;

	while (!q.empty()) {
		Floor now = q.front();
		q.pop();

		if (now.cur == G) {
			cout << now.cnt << endl;
			return;
		}

		int next = now.cur + U;
		if (next <= 1000000 && !visited[next]) {
			q.push({ next, now.cnt + 1 });
			visited[next] = true;
		}

		next = now.cur - D;
		if (next >= 1 && !visited[next]) {
			q.push({ next, now.cnt + 1 });
			visited[next] = true;
		}
	}//end while

	cout << "use the stairs" << endl;
}

int main() {
	// F:총 층수, G:스타트링크 위치, S:현재 층, U:위로, D:아래로
	cin >> F >> S >> G >> U >> D;
	bfs();
	return 0;
}