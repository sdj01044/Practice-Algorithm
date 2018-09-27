#include <iostream>
#include <cstring>		// memset
using namespace std;

#define A 0
#define B 99

int arr[100][2];

int dfs(int node) {
	if (node == B) {
		return 1;
	}
	else if (node == -1) {
		return 0;
	}
	else {
		if (dfs(arr[node][0]))
			return 1;
		if (dfs(arr[node][1]))
			return 1;
		return 0;
	}
}

int main() {
	for (int t = 0; t < 10; t++) {
		int T, N;
		cin >> T >> N;

		memset(arr, -1, sizeof(arr));
		for (int i = 0; i < N; i++) {
			int f, t;	cin >> f >> t;
			if (arr[f][0] == -1)
				arr[f][0] = t;
			else
				arr[f][1] = t;
		}

		bool ans = dfs(A);
		cout << "#" << T << " " << (ans ? 1 : 0) << endl;
	}
	return 0;
}