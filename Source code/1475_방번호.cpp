#include <iostream>
#include <string>
using namespace std;

int number[10];		// number[i] : i���ڸ� ����� ����

int main() {
	string n;
	cin >> n;
	
	int ans = 1;	// ���ڼ�Ʈ�� ��
	for (int i = 0; i < n.size(); i++) {
		char tmp[1] = { n[i] };
		int x = atoi(tmp);

		if (number[x] < ans) {	// ���ڸ� �ț����� ���ڸ� �������
			number[x]++;
		}
		else {
			if (x == 6 && number[9] < ans)	// 6�� �̹� ������ 9�� 6���� ����
				number[9]++;
			else if (x == 9 && number[6] < ans)	// 9�� �̹� ������ 6�� 9�� ����
				number[6]++;
			else {			// ���ڸ� �̹� ������ ��Ʈ�� �ϳ� �� ����
				ans++;
				number[x]++;
			}
		}
	}//end for

	cout << ans << endl;

	return 0;
}