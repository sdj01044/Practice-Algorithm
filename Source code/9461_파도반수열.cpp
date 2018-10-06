#include <iostream>
using namespace std;

long long p[101] = { 0,1,1,1,2,2,3,4,5,7,9 };

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		for (int i = 10; i <= 100; i++)
			p[i] = p[i - 1] + p[i - 5];

		cout << p[n] << endl;
	}
	return 0;
}