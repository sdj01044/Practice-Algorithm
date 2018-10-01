#include <iostream>
using namespace std;

int main() {
	long x;
	cin >> x;

	int sum = 0, i = 1;	
	while (true) {			// x번째 숫자가 i번째 대각선에 있는지 찾기
		if (sum + i+1 > x)
			break;
		sum += i;
		i++;
	}

	int u = i, d = 1;		// u : 분자 , d : 분모
	int diff = x - sum - 1;

	u -= diff;
	d += diff;

	if (i % 2 == 0) {		// 짝수번째 대각선은 세는 순서가 반대다.
		int tmp = u;
		u = d;
		d = tmp;
	}

	cout << u << "/" << d << endl;

	return 0;
}