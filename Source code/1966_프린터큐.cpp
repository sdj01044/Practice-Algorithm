#include <iostream>
#include <queue>
using namespace std;

int find_max(queue<pair<int,int>> q) {
	pair<int, int> max(-1, -1);
	int idx = 0;
	while (!q.empty()) {
		if (max.first < q.front().first) {
			max.first = q.front().first;
			max.second = idx;
		}
		idx++;
		q.pop();
	}
	return max.second;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		queue< pair<int,int> > q;
		for (int i = 0; i < N; i++) {
			int priority;
			cin >> priority;
			pair<int,int> p(priority, i);
			q.push(p);
		}

		int cnt = 1;
		while (!q.empty()) {
			int idx = find_max(q);
			for (int i = 0; i < idx; i++) {
				pair<int, int> tmp = q.front();
				q.pop();
				q.push(tmp);
			}
			if (q.front().second == M) {
				cout << cnt << endl;
				break;
			}
			else {
				q.pop();
				cnt++;
			}
		}
	}
	return 0;
}