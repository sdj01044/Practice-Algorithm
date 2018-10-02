#include <iostream>
#include <queue>
using namespace std;

struct Relation {
	int related;
	int count;
};

bool arr[101][101];
bool visited[101];

int bfs(int N, int start, int end) {
	queue<Relation> q;

	q.push({start, 0});
	visited[start] = true;

	while (!q.empty()) {
		Relation now = q.front();
		q.pop();

		if (now.related == end)
			return now.count;

		for (int i = 1; i <= N; i++) {
			if (!visited[i] && arr[now.related][i]) {
				q.push({ i, now.count + 1 });
				visited[i] = true;
			}
		}//end for
	}//end while
	return -1;
}

int main() {
	int N, M;	cin >> N;	// ��ü ����� ��, ������ ����
	int target1, target2;	// �̼��� ����ؾ��ϴ� ���
	cin >> target1 >> target2;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int x, y;	cin >> x >> y;	// �θ�, �ڽ�
		arr[y][x] = arr[x][y] = true;
	}

	cout << bfs(N, target1, target2) << endl;

	return 0;
}