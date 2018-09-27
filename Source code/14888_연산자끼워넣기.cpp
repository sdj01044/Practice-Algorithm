#include <iostream>
#include <vector>
using namespace std;

#define MAX 11
#define L_MAX 1000000000
#define L_MIN -1000000000
int arr[MAX];
int num_op[4];	// +, -, *, /
int N;
long _max = L_MIN, _min = L_MAX;

void calculate(vector<int> v) {
	int idx = 1, res = arr[0];
	for(int i=0; i<N-1; i++) {
		int now = v[i];
		switch (now)
		{case 0: {		// +
			res += arr[idx];
			break;
		}case 1: {		// -
			res -= arr[idx];
			break;
		}case 2: {		// *
			res *= arr[idx];
			break;
		}case 3: {		// /
			if (res < 0 && arr[idx] > 0) {
				res *= -1;
				res /= arr[idx];
				res *= -1;
			}
			else
				res /= arr[idx];
			break;
		}			
		}
		idx++;
	}//end while
	if (res > _max)
		_max = res;
	if (res < _min)
		_min = res;
}

void dfs(vector<int> v, int depth) {	// 연산자의 조합 구하기
	if (depth == N - 1) {	// 계산하기
		calculate(v);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (num_op[i] > 0) {
			num_op[i]--;
			v[depth] = i;
			dfs(v, depth + 1);
			num_op[i]++;
		}
	}//end for
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> num_op[i];
	}

	vector<int> v(N-1);		// queue를 쓰면 FIFO라서 조합못구함
	dfs(v, 0);
	cout << _max << endl << _min << endl;
	return 0;
}