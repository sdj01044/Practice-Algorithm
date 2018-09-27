#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 11
int arr[MAX];
int op[4];
int N, _min = 1000000000, _max = -1000000000;

void calc(vector<int> v) {		// next_permutation을 이용해서 구현, dfs보다 빨라졌다.
	do{
		int size = v.size();
		int res = arr[0], idx = 1;
		for (int i = 0; i < size; i++) {
			switch (v[i]) {
			case 0: {	// +
				res += arr[idx];
				break;
			}case 1: {	// -
				res -= arr[idx];
				break;
			}case 2: {	// *
				res *= arr[idx];
				break;
			}case 3: {	// /
				res /= arr[idx];
				break;
			}				
			}
			idx++;
		}
		if (res > _max)
			_max = res;
		if (res < _min)
			_min = res;
	} while (next_permutation(v.begin(), v.end()));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vector<int> v;
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
		if (op[i] > 0) {
			for (int j = op[i]; j > 0; j--) {
				v.push_back(i);
			}
		}
	}
	calc(v);
	cout << _max << '\n' << _min << '\n';
	return 0;
}