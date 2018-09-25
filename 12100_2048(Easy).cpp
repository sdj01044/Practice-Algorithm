#include <iostream>
#include <cstring>
using namespace std;

#define MAX 20
int arr[MAX][MAX];	// 0은 빈칸
bool sumed[MAX][MAX];
int N, ans = 0;

void dfs(int d, int depth) {
	if (depth > 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (ans < arr[i][j])
					ans = arr[i][j];
			}
		}
		return;
	}

	switch (d){
	case 0: {		// 위
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] != 0) {	// 0이 아니면 위로 땡기기
					for (int k = i; k > 0; k--) {
						if (arr[k - 1][j] == 0) {
							arr[k - 1][j] = arr[k][j];
							arr[k][j] = 0;
						}
						else if (arr[k - 1][j] == arr[k][j] && !sumed[k - 1][j] && !sumed[k][j]) {
							arr[k - 1][j] *= 2;
							arr[k][j] = 0;
							sumed[k - 1][j] = true;
						}
						else
							break;
					}//end for
				}
			}//end for
		}//end for
		memset(sumed, false, sizeof(sumed));
		break;
	}case 1: {		// 아래
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] != 0) {	// 0이 아니면 아래로 땡기기
					for (int k = i; k < N - 1; k++) {
						if (arr[k + 1][j] == 0) {
							arr[k + 1][j] = arr[k][j];
							arr[k][j] = 0;
						}
						else if (arr[k + 1][j] == arr[k][j] && !sumed[k + 1][j] && !sumed[k][j]) {
							arr[k + 1][j] *= 2;
							arr[k][j] = 0;
							sumed[k + 1][j] = true;
						}
						else
							break;
					}//end for
				}
			}//end for
		}//end for
		memset(sumed, false, sizeof(sumed));
		break;
	}case 2: {		// 왼
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if (arr[i][j] != 0) {	// 0이 아니면 왼쪽으로 땡기기
					for (int k = j; k > 0; k--) {
						if (arr[i][k -1] == 0) {
							arr[i][k -1] = arr[i][k];
							arr[i][k] = 0;
						}
						else if (arr[i][k -1] == arr[i][k] && !sumed[i][k -1] && !sumed[i][k]) {
							arr[i][k -1] *= 2;
							arr[i][k] = 0;
							sumed[i][k -1] = true;
						}
						else
							break;
					}//end for
				}
			}//end for
		}//end for
		memset(sumed, false, sizeof(sumed));
		break;
	}case 3: {		// 오
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (arr[i][j] != 0) {	// 0이 아니면 왼쪽으로 땡기기
					for (int k = j; k < N - 1; k++) {
						if (arr[i][k + 1] == 0) {
							arr[i][k + 1] = arr[i][k];
							arr[i][k] = 0;
						}
						else if (arr[i][k + 1] == arr[i][k] && !sumed[i][k + 1] && !sumed[i][k]) {
							arr[i][k + 1] *= 2;
							arr[i][k] = 0;
							sumed[i][k + 1] = true;
						}
						else
							break;
					}//end for
				}
			}//end for
		}//end for
		memset(sumed, false, sizeof(sumed));
		break;
	}
	}//end switch

	int arr_tmp[MAX][MAX];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr_tmp[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {	// 4방향
		dfs(i, depth + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = arr_tmp[i][j];
			}
		}
	}
}

int main() {
	int arr_tmp[MAX][MAX];
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			arr_tmp[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {	// 4방향
		dfs(i, 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				arr[i][j] = arr_tmp[i][j];
			}
		}
	}
	cout << ans << endl;
	return 0;
}