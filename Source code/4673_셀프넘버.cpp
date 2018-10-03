#include <iostream>
using namespace std;

bool creator[10000];		// false : 셀프넘버

void self(int n) {
	if (n > 10000)
		return;
	int next = n + n%10;	// n과 일의 자리를 더해줌

	while (true) {			// 십의 자리부터 각자리수 더해줌
		if (n / 10 != 0) {
			n /= 10;
			next += n % 10;
		}
		else
			break;
	}

	if (!creator[next]) {		// 이미 체크했으면 재귀안함
		creator[next] = true;
		self(next);				// 재귀
	}
}

int main() {
	for(int i=1; i<10000; i++)
		self(i);

	for (int i = 1; i < 10000; i++) {
		if (!creator[i])
			cout << i << endl;
	}

	return 0;
}