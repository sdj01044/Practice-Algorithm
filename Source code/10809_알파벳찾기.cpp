#include <iostream>
using namespace std;

int main() {
	int arr[26];
	for (int i = 0; i < 26; i++)	// �迭 �ʱ�ȭ
		arr[i] = -1;

	char* s = new char[100];
	cin >> s;						// ���ڿ� �Է�

	for (int i = 0; s[i] != '\0'; i++) {
		int c = s[i] - 97;
		if (arr[c] == -1)
			arr[c] = i;
	}

	for (int i = 0; i < 26; i++)	// �� ���
		cout << arr[i] << " ";

	return 0;
}