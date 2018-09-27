#include <iostream>
#include <algorithm>
using namespace std;

int arr[100];

int main() {
	for (int T = 1; T <= 10; T++) {
		int ans = 0, N;
		cin >> N;

		for (int i = 0; i < 100; i++)
			cin >> arr[i];

		while (N--) {
			sort(arr, arr + 100);
			arr[0]++;
			arr[99]--;
		}
		sort(arr, arr + 100);
		ans = arr[99] - arr[0];

		cout << "#" << T << " " << ans << endl;
	}

	return 0;
}