#include <iostream>
using namespace std;

/*long long arr[1000001];

int main() {
	long long N, B, C;
	cin >> N;

	for (long long i = 0; i<N; i++)
		cin >> arr[i];
	cin >> B >> C;

	long total = N;
	for (long long i = 0; i<N; i++) {
		arr[i] -= B;
		if (arr[i] > 0) {
			total += arr[i] / C;
			if (arr[i] % C > 0)
				total++;
		}
	}
	cout << total;
	return 0;
}*/


int main() {
	int N; // ������ ����
	int B; // �Ѱ������� ���� ������ ��
	int C; // �ΰ������� ���� ������ ��
	int x; // �ΰ������� ��

	long count = 0; // �� �ʿ��� ������ ��
	cin >> N;
	int *ai = new int[N]; // ������ ��

	for (int i = 0; i < N; i++) {
		cin >> ai[i];
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		x = 0;
		if (ai[i] <= B) {
			count++;
		}
		else {
			x = ((ai[i] - B) / C);
			count = count + x + 1;
			if ((ai[i] - B) % C > 0) {
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}