#include <iostream>
using namespace std;

int f(int n, int m) {
	if (m == 1) return n;
	return n*f(n, m - 1);
}

int main() {
	for (int i = 0; i<10; i++) {
		int T;	cin >> T;
		int N, M;	cin >> N >> M;
		cout << "#" << T << " "<< f(N, M) << endl;
	}
	return 0;
}