#include <iostream>
#include <string>
using namespace std;

int S[13];
int K, cnt;

void print(string s) {
	cout << s << endl;
}

void dfs(int idx, string str) {		// dfs 백트래킹을 이용
	if (cnt == 6) {
		print(str);		// 개수가 6이면 출력
	}
	else {
		for (int i = idx + 1; i < K; i++) {
			cnt++;
			string tmp, t = str;
			tmp = to_string(S[i]);
			t.append(tmp + " ");
			dfs(i, t);
		}
	}
	cnt--;		// 백트래킹 부분, 뒤부터 숫자를 선택안한걸로 바꾸어준다.
}

int main() {
	while (1) {
		cin >> K;
		if (K == 0)
			break;
		for (int i = 0; i < K; i++) {
			cin >> S[i];
		}

		for (int i = 0; i < K; i++) {
			cnt = 1;
			string tmp;
			tmp = to_string(S[i]);
			tmp.append(" ");
			dfs(i, tmp);
		}
		cout << endl;
	}
	return 0;
}