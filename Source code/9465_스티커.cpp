#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 100000

int sticker[2][MAX];
int d[MAX][3];	// d[i][0]:¾È¶¼±â, d[i][1]:À§¿¡ ¶¼±â, d[i][2]:¹Ø¿¡ ¶¼±â

int bottomUp(int N) {
	for (int i = 0; i < N; i++) {
		d[i + 1][0] = max(d[i + 1][0], max(d[i][0], max(d[i][1], d[i][2])));
		d[i + 1][1] = max(d[i + 1][1], max(d[i][0], d[i][2])) + sticker[0][i];
		d[i + 1][2] = max(d[i + 1][2], max(d[i][0], d[i][1])) + sticker[1][i];
	}
	return max(d[N][0], max(d[N][1], d[N][2]));
}

int main() {
	int T; cin >> T;
	while (T--) {
		int N;	cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> sticker[i][j];
			}
		}
		cout << bottomUp(N) << endl;
		memset(d, 0, sizeof(d));
	}//end while
	return 0;
}