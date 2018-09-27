#include <iostream>
using namespace std;

int price_2017[22] = {0, 500, 300, 300, 200, 200, 200, 50, 50, 50, 50, 30, 30, 30, 30, 30, 10, 10 , 10 , 10 , 10 , 10 };
int price_2018[32] = { 0, 512, 256, 256, 128, 128 , 128 , 128, 64, 64 , 64 , 64 , 64 , 64 , 64 , 64, 32, 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 , 32 };

int main() {
	int T;
	while (T--) {
		int a, b, sum = 0;
		cin >> a >> b;

		if (a <= 21) {		// a 상금
			a = price_2017[a];
		}
		else {
			a = 0;
		}

		if (b <= 31) {		// b 상금
			b = price_2018[b];
		}
		else {
			b = 0;
		}

		cout << a + b << endl;
	}

	return 0;
}