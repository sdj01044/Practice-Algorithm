#include <stdio.h>

char S[100];

int main() {
	scanf("%s", S);
	
	for (int i = 'a'; i <= 'z'; i++) {
		int j = 0;
		for (j; j < 100; j++) {
			if (S[j] == i) {
				printf("%d", j);
				break;
			}
		}
		if (j == 100)
			printf("-1");
		printf(" ");
	}
	
	return 0;
}