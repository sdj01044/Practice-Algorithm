#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 1000001
int d[MAX];

int f(int N) {		// topDown
	if (N == 1) return 0;
	if (d[N] != -1) return d[N];	// �̹� �����

	int res = f(N - 1) + 1;
	if (N % 2 == 0) res = min(res, f(N / 2) + 1);
	if (N % 3 == 0) res = min(res, f(N / 3) + 1);
	d[N] = res;
	return res;
}

// d[i] : i�� 1�� ����µ� �ʿ��� �ּ� �����
void bottomUp(int n) {		
	d[1] = 0;		// �ʱⰪ
	d[2] = 1;
	d[3] = 1;

	for (int i = 4; i <= n; i++) {
		d[i] = d[i - 1] + 1;	// -1

		int tmp;
		if (i % 3 == 0) {		// /3
			tmp = d[i / 3] + 1;
			if (tmp < d[i])
				d[i] = tmp;
		}

		if (i % 2 == 0) {		// /2
			tmp = d[i / 2] + 1;
			if (tmp < d[i])
				d[i] = tmp;
		}
	}
}

int main() {
	int N;
	cin >> N;
	memset(d, -1, sizeof(d));	// f()���� �ʿ�
	cout << f(N) << endl;
	//cout << d[N] << endl;		// bottumUp()�� �� ������.
	return 0;
}