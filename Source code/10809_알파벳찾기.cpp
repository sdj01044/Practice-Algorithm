#include <iostream>
using namespace std;

int main() {
	int arr[26];
	for (int i = 0; i < 26; i++)	// 배열 초기화
		arr[i] = -1;

	char* s = new char[100];
	cin >> s;						// 문자열 입력

	for (int i = 0; s[i] != '\0'; i++) {
		int c = s[i] - 97;
		if (arr[c] == -1)
			arr[c] = i;
	}

	for (int i = 0; i < 26; i++)	// 답 출력
		cout << arr[i] << " ";

	return 0;
}