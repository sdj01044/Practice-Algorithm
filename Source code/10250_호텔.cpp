#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int h, w, n;
		cin >> h >> w >> n;

		int x = n / h + 1, y = n % h;	// x:방 호수, y:방 층수
		if (y == 0) {
			y = h;
			x--;
		}

		if (x < 10)
			cout << y << "0" << x << endl;
		else
			cout << y << x << endl;
	}
	return 0;
}