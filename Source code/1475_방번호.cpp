#include <iostream>
#include <string>
using namespace std;

int number[10];		// number[i] : i숫자를 사용한 개수

int main() {
	string n;
	cin >> n;
	
	int ans = 1;	// 숫자세트의 수
	for (int i = 0; i < n.size(); i++) {
		char tmp[1] = { n[i] };
		int x = atoi(tmp);

		if (number[x] < ans) {	// 숫자를 안썻으면 숫자를 사용하자
			number[x]++;
		}
		else {
			if (x == 6 && number[9] < ans)	// 6을 이미 썻으면 9를 6으로 쓰자
				number[9]++;
			else if (x == 9 && number[6] < ans)	// 9를 이미 썻으면 6을 9로 쓰자
				number[6]++;
			else {			// 숫자를 이미 썻으면 세트를 하나 더 사자
				ans++;
				number[x]++;
			}
		}
	}//end for

	cout << ans << endl;

	return 0;
}