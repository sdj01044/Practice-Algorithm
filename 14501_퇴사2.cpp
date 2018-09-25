#include <iostream>
using namespace std;

#define MAX 15
int T[MAX];
int P[MAX];
int N, _max = 0;

void go(int day, int sum) {
	if (day == N) {
		if (_max < sum)
			_max = sum;
		return;
	}
	if (day > N)	// day가 최대 넘어가면 끝
		return;
	go(day + T[day], sum + P[day]);	// 현재 day에 상담 진행
	go(day + 1, sum);	// 현재 day에 상담을 안함
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	go(0, 0);
	cout << _max << '\n';
	return 0;
}