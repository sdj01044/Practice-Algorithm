#include <iostream>
using namespace std;

bool arr[10001];	// false : �Ҽ�

void check_prime(int n) {
	for (int i = 2; i*i <= n; i++) {	// ������ ������ ��Ʈn ������ üũ�ص� ��
		if (arr[i])		// �̹� üũ�� ����� Ȯ�� ����
			continue;
		for (int j = i+i; j <= n; j += i)	
			arr[j] = true;		// i�� ����� üũ
	 }
}

int main() {
	int m, n;
	cin >> m >> n;

	arr[0] = true;
	arr[1] = true;
	check_prime(n);
	
	int sum = 0;
	int min = 0;
	for (int i = m; i <= n; i++) {
		if (!arr[i]) {
			sum += i;		// �Ҽ����� ��
			if (min == 0)
				min = i;		// �ּ� �Ҽ�
		}
	}//end for

	if (sum != 0)
		cout << sum << endl << min;
	else
		cout << "-1" << endl;

	return 0;
}