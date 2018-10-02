#include <iostream>
using namespace std;

bool arr[10001];	// false : 소수

void check_prime(int n) {
	for (int i = 2; i*i <= n; i++) {	// 수학적 원리로 루트n 까지만 체크해도 됨
		if (arr[i])		// 이미 체크한 배수는 확인 안함
			continue;
		for (int j = i+i; j <= n; j += i)	
			arr[j] = true;		// i의 배수들 체크
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
			sum += i;		// 소수들의 합
			if (min == 0)
				min = i;		// 최소 소수
		}
	}//end for

	if (sum != 0)
		cout << sum << endl << min;
	else
		cout << "-1" << endl;

	return 0;
}