#include <iostream>
using namespace std;
#define R 300

int range[R] = {0, 1,};

int main() {
	int T;
	cin >> T;

	for (int i = 2; i < R; i++) {
		range[i] = range[i - 1] + (i - 1);
	}

	for (int test_case = 1; test_case <= T; test_case++) {
		int p, q;
		cin >> p >> q;

		int p_y, p_x, q_y, q_x;
		for (int i = 1; i < R-1; i++) {		// y값 기준으로, 어느 대각선에 포함되는지 구하기
			if (range[i] <= p && range[i + 1] > p) {
				p_y = i - (p - range[i]);
				p_x = p - range[i] + 1;
			}
			if (range[i] <= q && range[i + 1] > q) {
				q_y = i - (q - range[i]);
				q_x = q - range[i] + 1;
			}
		}

		int ans_y = p_y + q_y, ans_x = p_x + q_x;
		int ans = range[ans_y], gap = ans_y+1;
		for (int i = 1; i < ans_x; i++)
			ans += gap++;
		
		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}