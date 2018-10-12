#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	deque<int> dq;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	int cnt = 0;
	while (M--) {
		int target, l_cnt = 0, r_cnt = 0;
		cin >> target;
		deque<int> lq = dq, rq = dq;
		while (lq.front() != target) {
			int tmp = lq.front();
			lq.pop_front();
			lq.push_back(tmp);
			l_cnt++;
		}

		while (rq.front() != target) {
			int tmp = rq.back();
			rq.pop_back();
			rq.push_front(tmp);
			r_cnt++;
		}

		if (l_cnt > r_cnt) {
			dq = rq;
			cnt += r_cnt;
		}
		else {
			dq = lq;
			cnt += l_cnt;
		}
		dq.pop_front();
	}
	cout << cnt << endl;
	return 0;
}