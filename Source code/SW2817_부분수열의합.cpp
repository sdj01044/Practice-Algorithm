#include <iostream>
using namespace std;

int* arr;

int main() {
	int T;
	cin >> T;

	int test_case;
	for (test_case = 1; test_case <= T; test_case++) {
		int Answer = 0;
		int N, K;
		cin >> N >> K;

		arr = new int[N];
		for (int i = 0; i < N; i++)
			cin >> arr[i];



		cout << "#" << test_case << " " << Answer << endl;
	}

	return 0;
}