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
		// atoi의 인자가 const char* 라서 그냥 char는 안된다
		ans += atoi(tmp);	
	}

	cout << ans << endl;

	return 0;
}