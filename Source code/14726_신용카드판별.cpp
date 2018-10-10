#include <iostream>
#include <string>
using namespace std; 

#define CARD_NUM 16

int main() {
	int T;
	cin >> T;

	while (T--) {
		string input;
		cin >> input;

		int arr[16];
		string tmp = input;
		for (int i = CARD_NUM-1; i > -1; i--) {
			int target = atoi(tmp.substr(i, 1).c_str());
			if (i % 2 == 0) {
				target *= 2;
				if (target >= 10) {
					target = target % 10 + target / 10;
				}
			}
			arr[i] = target;
		}//end for

		int sum = 0;
		for (int i = 0; i < CARD_NUM; i++) {
			sum += arr[i];
		}

		if (sum % 10 == 0)
			cout << "T" << endl;
		else
			cout << "F" << endl;
	}

	return 0;
}