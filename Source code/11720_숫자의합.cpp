#include <string>
#include <iostream>
using namespace std;

int main() {
	string input;
	int n;
	
	cin >> n;
	cin >> input;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		char tmp[1] = { input[i] };
		// atoi�� ���ڰ� const char* �� �׳� char�� �ȵȴ�
		ans += atoi(tmp);	
	}

	cout << ans << endl;

	return 0;
}