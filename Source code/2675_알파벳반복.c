#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int R;
		char S[21];
		scanf("%d %s", &R, S);


		for (int i = 0; S[i] != '\0'; i++) {
			for (int k = 0; k < R; k++) {
				printf("%c",S[i]);
			}
		}
		printf("\n");
	}
	return 0;
}