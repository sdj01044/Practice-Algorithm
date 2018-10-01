#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int people[4];

	for (int i = 0; i < 4; i++) {
		int d, u;
		cin >> d >> u;
		sum += u - d;
		people[i] = sum;
	}

	int g = people[0];
	for (int i = 1; i < 4; i++) {
		if (people[i] > g)
			g = people[i];
	}

	cout << g << endl;

	return 0;
}