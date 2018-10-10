#include <string>
#include <iostream>
using namespace std;

int main() {
	string input;
	cin >> input;

	for (int i = 0; i<input.size(); i++) {
		if (i != 0 && i % 10 == 0)
			cout << endl;
		cout << input[i];
	}

	return 0;
}