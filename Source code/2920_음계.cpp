/*#include <iostream>
using namespace std;

int main() {
	int code[9];
	int ans, j = 8;

	for (int i = 1; i <= 8; i++) {
		cin >> code[i];

		if (code[i] == i)
			ans = 0;
		else if (code[i] == j)
			ans = 1;
		else
			ans = 2;
		j--;
	}

	if (ans == 0)
		cout << "ascending";
	else if (ans == 1)
		cout << "descending";
	else
		cout << "mixed";

	return 0;
}*/

#include <stdio.h>
int main() {
	int arr[8], a = 0, d = 0, i;

	for (i = 0; i < 8; i++) {
		scanf_s("%d", &arr[i]);

		if (i + 1 == arr[i])
			a++;
		else if (8 - i == arr[i])
			d++;
	}

	if (a == 8)
		printf("ascending");
	else if (d == 8)
		printf("descending");
	else
		printf("mixed");
}