#include <iostream>
#include <string>
using namespace std;

int arr[123];

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		str[i] = tolower(str[i]);
		int ch = (int)str[i];
		arr[ch]++;
	}

	char answer;
	int max = 0, max_idx;
	for (int i = 97; i < 123; i++) {
		if (arr[i] > max) {
			max = arr[i];
			answer = (char)i;
		}
		else if (arr[i] == max) {
			answer = '?';
		}
	}
	cout << (char)toupper(answer) << endl;
	return 0;
}