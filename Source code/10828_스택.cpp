#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack{
private:
	vector<int> elements;
	int capa = 0;
	int front = -1;
public:
	void push(int x) {
		elements.push_back(x);
		capa++;
		front++;
	}

	int pop() {
		int ans;
		if (capa > 0) {
			int tmp = front;
			front--;
			capa--;
			ans = elements[tmp];
			elements.pop_back();
		}
		else {
			ans = -1;
		}
		return ans;
	}

	int size() {
		return capa;
	} 

	int empty() {
		if (capa == 0)
			return 1;
		else
			return 0;
	}

	int top() {
		if (capa > 0) {
			return elements[front];
		}
		else {
			return -1;
		}
	}
};

int main() {
	int N;
	cin >> N;

	Stack s;
	while (N--) {
		string cmd;
		cin >> cmd;
		if (cmd.compare("push") == 0) {
			int x;
			cin >> x;
			s.push(x);
		}
		else if (cmd.compare("top") == 0) {
			cout << s.top() << endl;
		}
		else if (cmd.compare("size") == 0) {
			cout << s.size() << endl;
		}
		else if (cmd.compare("pop") == 0) {
			cout << s.pop() << endl;
		}
		else {
			cout << s.empty() << endl;
		}
	}
	return 0;
}
