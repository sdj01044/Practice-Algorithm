#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	deque<int> dq;
	int N;
	cin >> N;

	while (N--) {
		string str;
		cin >> str;
		int K;

		if (str.compare("push_back") == 0) {
			cin >> K;
			dq.push_back(K);
		}
		else if (str.compare("push_front") == 0) {
			cin >> K;
			dq.push_front(K);
		}
		else if (str.compare("front") == 0) {
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.front() << endl;
		}
		else if (str.compare("back") == 0) {
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.back() << endl;
		}
		else if (str.compare("pop_front") == 0) {
			if (dq.empty())
				cout << -1 << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (str.compare("pop_back") == 0) {
			if (dq.empty())
				cout << -1 << endl;
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (str.compare("size") == 0) {
			cout << dq.size() << endl;
		}
		else {	// empty
			if (dq.empty()) {
				cout << 1 << endl;
			}
			else
				cout << 0 << endl;
		}
	}
	return 0;
}