#include <iostream>
using namespace std;

int n;
int arr[80];	// arr[x] : x자리 수열의 숫

bool promising(int x) {

}

int backTracking(int x) {
	if (x == n)
		return 1;

	int ans = 0;
	if (promising(x)) {
		ans += backTracking(x + 1);
	}
	return ans;
}

int main() {
	cin >> n;

	int ans = backTracking(1);
	cout << ans << endl;
	return 0;
}