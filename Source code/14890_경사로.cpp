#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100
int arr[MAX][MAX];
bool visited[MAX];
int N, L;

int path_horizontal(int x) {
	for (int i = 0; i < N - 1; i++) {
		if (arr[x][i] != arr[x][i + 1]) {
			if (abs(arr[x][i] - arr[x][i + 1]) > 1) {
				memset(visited, false, sizeof(visited));
				return 0;
			}

			if (arr[x][i] > arr[x][i + 1]) {	// 다음 높이가 낮아지는 경우
				for (int k = i + 1; k <= i + L; k++) {
					if (visited[k] || arr[x][k] != arr[x][i + 1]) {
						memset(visited, false, sizeof(visited));
						return 0;
					}
					visited[k] = true;
				}
			}
			else {								// 다음 높이가 높아지는 경우
				for (int k = i + 1 - L; k <= i; k++) {
					if (visited[k] || arr[x][k] != arr[x][i]) {
						memset(visited, false, sizeof(visited));
						return 0;
					}
					visited[k] = true;
				}
			}
		}
	}//end for
	memset(visited, false, sizeof(visited));
	return 1;
}

int path_vertical(int y) {
	for (int i = 0; i < N - 1; i++) {
		if (arr[i][y] != arr[i + 1][y]) {
			if (abs(arr[i][y] - arr[i + 1][y]) > 1) {
				memset(visited, false, sizeof(visited));
				return 0;
			}

			if (arr[i][y] > arr[i + 1][y]) {	// 다음 높이가 낮아지는 경우
				for (int k = i + 1; k <= i + L; k++) {
					if (visited[k] || arr[k][y] != arr[i+1][y]) {
						memset(visited, false, sizeof(visited));
						return 0;
					}
					visited[k] = true;
				}
			}
			else {								// 다음 높이가 높아지는 경우
				for (int k = i + 1 - L; k <= i; k++) {
					if (visited[k] || arr[k][y] != arr[i][y]) {
						memset(visited, false, sizeof(visited));
						return 0;
					}
					visited[k] = true;
				}
			}
		}
	}//end for
	memset(visited, false, sizeof(visited));
	return 1;
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += path_vertical(i);
		ans += path_horizontal(i);
	}
	cout << ans << endl;
	return 0;
}