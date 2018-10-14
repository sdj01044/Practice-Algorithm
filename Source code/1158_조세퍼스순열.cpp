#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < M-1; i++) {
			int f = q.front();
			q.pop();
			q.push(f);
		}
		if (q.size() == 1) {
			cout << q.front() << ">";
		}else {
			cout << q.front() << ", ";
		}
		q.pop();
	}

	return 0;
}