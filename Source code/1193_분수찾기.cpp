#include <iostream>
using namespace std;

int main() {
	long x;
	cin >> x;

	int sum = 0, i = 1;	
	while (true) {			// x��° ���ڰ� i��° �밢���� �ִ��� ã��
		if (sum + i+1 > x)
			break;
		sum += i;
		i++;
	}

	int u = i, d = 1;		// u : ���� , d : �и�
	int diff = x - sum - 1;

	u -= diff;
	d += diff;

	if (i % 2 == 0) {		// ¦����° �밢���� ���� ������ �ݴ��.
		int tmp = u;
		u = d;
		d = tmp;
	}

	cout << u << "/" << d << endl;

	return 0;
}