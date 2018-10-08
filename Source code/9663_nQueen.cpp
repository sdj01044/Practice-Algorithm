#include <iostream>
using namespace std;

int n;
/*bool chess[15][15];

bool promising(int row, int col) {
	bool result = true;

	for (int i = row-1; i >= 0; i--) {	// ���� �� Ȯ��
		if (chess[i][col]) {
			result = false;
			break;
		}
	}//end for

	int x = row - 1, y = col - 1;		// ���� �� �밢�� Ȯ��
	while (x >= 0 && y >= 0) {
		if (chess[x][y]) {
			result = false;
			break;
		}
		x -= 1;
		y -= 1;
	}

	x = row - 1, y = col + 1;		// ������ �� �밢�� Ȯ��
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
			ans += backTracking(row + 1);	// ���
			chess[row][col] = false;
		}
	}//end for
	return ans;
}*/

int col[15];	// col[i] : i��(����)�� ���� �ִ� ���ȣ(����)

bool promising(int r, int c) {
	for (int i = 0; i < r; i++) {
		if (col[i] == c || abs(col[i]-c) == r - i)	// ���ο� �밢�� üũ
			return false;
	}
	return true;
}

int nQueen(int r) {		// r : ��(����), c : ��(����)
	if (r == n)
		return 1;

	int ans = 0;
	for (int c = 0; c < n; c++) {
		if (promising(r, c)) { 
			col[r] = c;
			ans += nQueen(r + 1);	// ���
		}
	}
	return ans;
}

int main() {
	cin >> n;

	//int ans = backTracking(0);	// �ð��� �����ɸ�
	int ans = nQueen(0);
	cout << ans << endl;
	return 0;
}