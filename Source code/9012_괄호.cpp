#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	while (N--) {
		string str, answer="YES";
		stack<char> s;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			char ch = str[i];
			if(ch == '(')
				s.push(ch);
			else {
				if (s.empty()) {
					answer = "NO";
					break;
				}
				else {
					s.pop();
				}
			}
		}//end for
		if (!s.empty())
			answer = "NO";
		cout << answer << endl;
	}
	return 0;
}