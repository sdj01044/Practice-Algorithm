#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, answer = 0;
	cin >> N;

	for (int t = 0; t < N; t++) {
		int arr[26] = { 0 };	// a~z (97~122)
		string str;
		cin >> str;
		int i;
		for (i = 0; i < str.size(); i++) {
			if (str[i] == str[i + 1])
				continue;
			else {
				if (arr[str[i] - 97] == 0)
					arr[str[i] - 97]++;
				else
					break;
			}
		}
		if (i == str.size())
			answer++;
	}
	cout << answer << endl;
	return 0;
}