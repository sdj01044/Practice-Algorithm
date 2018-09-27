#include <iostream>
#include <string.h>
using namespace std;

int main() {
	for (int T = 1; T <= 10; T++) {
		int arr[101], t;
		cin >> t;
		for (int i = 0; i < 101; i++)
			arr[i] = 0;

		for (int i = 0; i < 1000; i++) {
			int score;
			cin >> score;
			arr[score]++;
		}

		int ans = 0;
		for (int i = 0; i < 101; i++) {
			if (arr[i] >= arr[ans])
				ans = i;
		}

		cout << "#" << T << " " << ans << endl;
		memset(arr, 0, 101 * sizeof(int));
	}
	return 0;
}