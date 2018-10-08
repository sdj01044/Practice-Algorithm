#include <iostream>
using namespace std;

int n;
/*bool chess[15][15];

bool promising(int row, int col) {
	bool result = true;

	for (int i = row-1; i >= 0; i--) {	// 위쪽 열 확인
		if (chess[i][col]) {
			result = false;
			break;
		}
	}//end for

	int x = row - 1, y = col - 1;		// 왼쪽 위 대각선 확인
	while (x >= 0 && y >= 0) {
		if (chess[x][y]) {
			result = false;
			break;
		}
		x -= 1;
		y -= 1;
	}

	x = row - 1, y = col + 1;		// 오른쪽 위 대각선 확인
	while (x >= 0 && y < n) {
		if (chess[x][y]) {
			result = false;
			break;
		}
		x -= 1;
		y += 1;
	}

	return result;
}

int backTracking(int row) {
	if (row == n)
		return 1;
	
	int ans = 0;
	for (int col = 0; col < n; col++) {
		if (promising(row, col)) {
			chess[row][col] = true;
			ans += backTracking(row + 1);	// 재귀
			chess[row][col] = false;
		}
	}//end for
	return ans;
}*/

int col[15];	// col[i] : i열(세로)의 퀸이 있는 행번호(가로)

bool promising(int r, int c) {
	for (int i = 0; i < r; i++) {
		if (col[i] == c || abs(col[i]-c) == r - i)	// 세로와 대각선 체크
			return false;
	}
	return true;
}

int nQueen(int r) {		// r : 열(세로), c : 행(가로)
	if (r == n)
		return 1;

	int ans = 0;
	for (int c = 0; c < n; c++) {
		if (promising(r, c)) { 
			col[r] = c;
			ans += nQueen(r + 1);	// 재귀
		}
	}
	return ans;
}

int main() {
	cin >> n;

	//int ans = backTracking(0);	// 시간이 오래걸림
	int ans = nQueen(0);
	cout << ans << endl;
	return 0;
}