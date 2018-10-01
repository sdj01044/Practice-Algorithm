#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;	// 큐의 크기
	int M;	// 뽑으려고 하는 개수
	cin >> N >> M;

	int* q = new int[N+1];
	for (int i = 0; i < N; i++) {
		q[i] = i;
	}

	int head = 0, min = -1, half = N / 2;
	for (int i = 0; i < M; i++) {
		int target;
		cin >> target;
		target--;

		int pivot = (head + half) % N;
		int count = 0;
		if (pivot > target) {	// 2번이 가까움
			if (target - head < 0) {
				while (q[head] != target) {
					head++;
					if (head == N)
						head = 0;
					if (q[head] == -1)
						continue;
					count++;
				}
			}
			else
				count = target - head;
		}
		else {					// 3번이 가까움
			while (q[head] != target) {
				head--;
				if (head == -1)
					head = N;
				if (q[head] == -1)
					continue;
				count++;
			}
		}

		if (min == -1)
			min = count;
		else if (min > count)
			min = count;

		q[head] = -1;
		N--;
	}

	for (int i = 0; i < N; i++)
		cout << q[i] << ",";
	cout << endl;
	cout << min << endl;

	return 0;
}