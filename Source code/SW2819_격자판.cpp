#include <iostream>
using namespace std;

#define N 10000000

int test_case;
int check_num[N];
int arr_num[16];
int Answer = 0;

void dfs(int start, int num, int depth) {
	num = num * 10 + arr_num[start];

	if (depth == 7) {
		if (check_num[num] != test_case) {
			check_num[num] = test_case;
			Answer++;
		}
		return;
	}

	if (start > 0 && (start - 1) % 4 != 3)		// 辑率
		dfs(start - 1, num, depth + 1);
	if ((start + 1) % 4 != 0)					// 悼率
		dfs(start + 1, num, depth + 1);
	if ((start + 4) < 16)						// 巢率
		dfs(start + 4, num, depth + 1);
	if ((start - 4) >= 0)						// 合率
		dfs(start - 4, num, depth + 1);

	return;
}

int main() {
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; test_case++) {
		
		for (int i = 0; i < 16; i++)
			cin >> arr_num[i];

		for(int i=0; i<16; i++)
			dfs(i, 0, 1);

		cout << "#" << test_case << " " << Answer << endl;
		Answer = 0;
	}

	return 0;
}