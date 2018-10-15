#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<int> s;
	string ans = "";
	int N, idx = 1;
	cin >> N;

	while (N--) {
		int input;
		cin >> input;

		if (s.empty()) {
			s.push(idx);
			idx++;
			ans += "+\n";
		}
		if(s.top() < input) {
			while(s.top() < input) {
				s.push(idx);
				idx++;
				ans += "+\n";
			}
		}
		else if (s.top() > input) {
			cout << "NO" << endl;
			return 0;
		}
		
		if (s.top() >= input) {
			while (!s.empty() && s.top() == input) {
				s.pop();
				ans += "-\n";
			}
		}
	}
	cout << ans;
	return 0;
}