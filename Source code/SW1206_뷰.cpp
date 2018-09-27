#include <iostream>
using namespace std;

int Max(int* arr, int idx) {
	int result, m1, m2;
	m1 = arr[idx - 1] > arr[idx + 1] ? idx - 1 : idx + 1;
	m2 = arr[idx - 2] > arr[idx + 2] ? idx - 2 : idx + 2;
	result = arr[m1] > arr[m2] ? m1 : m2;
	cout << "[" << idx << "]" << "result: " << result;
	return result;
}

int main() {
	for (int T = 1; T <= 1; T++) {
		int ans = 0, N;
		cin >> N;

		int* arr = new int[N];
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		
		for (int i = 2; i < N-2; i++) {
			if (arr[i] <= arr[i + 1] || arr[i] <= arr[i - 1])
				continue;
			if (arr[i] <= arr[i + 2] || arr[i] <= arr[i - 2])
				continue;

			int max_idx = Max(arr, i);
			int tmp_ans = arr[i] - arr[max_idx];
			cout << ", diff: " << tmp_ans << endl;
			ans += tmp_ans;
		}

		cout << "#" << T << " " << ans << endl;
	}

	return 0;
}