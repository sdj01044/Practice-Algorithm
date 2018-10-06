#include <iostream>
#include <queue>
using namespace std;

struct Floor {
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
	// F:�� ����, G:��ŸƮ��ũ ��ġ, S:���� ��, U:����, D:�Ʒ���
	cin >> F >> S >> G >> U >> D;
	bfs();
	return 0;
}