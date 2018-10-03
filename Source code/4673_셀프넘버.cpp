#include <iostream>
using namespace std;

bool creator[10000];		// false : �����ѹ�

void self(int n) {
	if (n > 10000)
		return;
	int next = n + n%10;	// n�� ���� �ڸ��� ������

	while (true) {			// ���� �ڸ����� ���ڸ��� ������
		if (n / 10 != 0) {
			n /= 10;
			next += n % 10;
		}
		else
			break;
	}

	if (!creator[next]) {		// �̹� üũ������ ��;���
		creator[next] = true;
		self(next);				// ���
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