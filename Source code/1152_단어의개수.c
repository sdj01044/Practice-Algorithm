/*#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);

	int len = s.length();
	int res = 0, i;
	for (i = 0; i < len-1; i++) {
		if (s.at(i) != ' ' && s.at(i+1) == ' ') {
			//cout << s.at(i) << endl;
			res++;
		}
	}
	if (s.at(i) != ' ')
		++res;
	cout << res << endl;
	return 0;
}*/

#include <stdio.h>
#define MAX 1000000
int main() {
	char *s = malloc(sizeof(char) * MAX);
	gets(s);
	int length = strlen(s);

	int i, cnt = 0;
	for (i = 0; i < length - 1; i++) {
		if (s[i] != ' ' && s[i + 1] == ' ') {
			cnt++;
		}
	}
	if (s[i] != ' ')
		cnt++;
	printf("%d\n", cnt);
	return 0;
}