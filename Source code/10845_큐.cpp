#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<int> q;

void choice(string o, int x) {
	if (o.compare("push") == 0) {
		q.push(x);
	}
	else if (o.compare("front") == 0) {
		if (!q.empty())
			cout << q.front() << endl;
		else
			cout << "-1" << endl;
	}
	else if (o.compare("back") == 0) {
		if (!q.empty())
			cout << q.back() << endl;
		else
			cout << "-1" << endl;
	}
	else if (o.compare("empty") == 0) {
		if (q.empty())
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	else if (o.compare("pop") == 0) {
		if (!q.empty()) {
			int f = q.front();
			cout << f << endl;
			q.pop();
		}
		else
			cout << "-1" << endl;
	}
	else {
		cout << q.size() << endl;
	}
}

int main() {
	int n;
	cin >> n;

	while (n--) {
		string order;
		int x = 0;

		cin >> order;
		if (order.compare("push") == 0)
			cin >> x;

		choice(order, x);
	}

	return 0;
}