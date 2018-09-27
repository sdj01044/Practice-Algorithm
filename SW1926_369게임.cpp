#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		bool flag = false;
		for (int j = i; j > 0; j /= 10) {
			if (j % 10 == 3
				|| j % 10 == 6
				|| j % 10 == 9) {
				cout << "-";
				flag = true;
			}
		}
		if (!flag)
			cout << i;
		cout << " ";
	}

	return 0;
}


/*int main() {
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		int tmp = i;
		bool flag = false;

		while (tmp > 0) {
			if (tmp % 10 == 3 || tmp % 10 == 6 || tmp % 10 == 9) {
				cout << "-";
				flag = true;
			}
			tmp /= 10;
		}

		if (!flag)
			cout << i << " ";
		else
			cout << " ";
	}

	return 0;
}*/