#include <iostream>
using namespace std;

#define MAX 20
int arr[MAX][MAX];
int dice[6];	// Áß¾Ó, À§, ¿À¸¥ÂÊ, ¾Æ·¡, ¿ÞÂÊ, ¹Ø¸é
int N, M, X, Y, K;

void set_tmparr(int* tmp, bool flag) {
	if (flag) {
		tmp[0] = dice[4];
		tmp[1] = dice[0];
		tmp[2] = dice[2];
		tmp[3] = dice[5];
	}
	else {
		tmp[0] = dice[1];
		tmp[1] = dice[0];
		tmp[2] = dice[3];
		tmp[3] = dice[5];
	}
}

void set_dice(int* tmp, bool flag) {
	if (flag) {
		dice[4] = tmp[0];
		dice[0] = tmp[1];
		dice[2] = tmp[2];
		dice[5] = tmp[3];
	}
	else {
		dice[1] = tmp[0];
		dice[0] = tmp[1];
		dice[3] = tmp[2];
		dice[5] = tmp[3];
	}
}

// 1,2 ¸í·É : 4, 0, 2, 5	3,4 ¸í·É : 1, 0, 3, 5
void move(int o) {
	int tmp_arr[4];
	switch (o) {
	case 1: {		// µ¿
		if (Y + 1 >= M) { return; }
		set_tmparr(tmp_arr, true);
		int tmp = tmp_arr[3];
		for (int i = 3; i > 0; i--) {
			tmp_arr[i] = tmp_arr[i - 1];
		}
		tmp_arr[0] = tmp;
		set_dice(tmp_arr, true);
		if (arr[X][++Y] != 0) {
			dice[5] = arr[X][Y];
			arr[X][Y] = 0;
		}
		else
			arr[X][Y] = dice[5];
		break;
	}
	case 2: {		// ¼­
		if (Y - 1 < 0) { return; }
		set_tmparr(tmp_arr, true);
		int tmp = tmp_arr[0];
		for (int i = 0; i < 3; i++) {
			tmp_arr[i] = tmp_arr[i + 1];
		}
		tmp_arr[3] = tmp;
		set_dice(tmp_arr, true);
		if (arr[X][--Y] != 0) {
			dice[5] = arr[X][Y];
			arr[X][Y] = 0;
		}
		else
			arr[X][Y] = dice[5];
		break;
	}
	case 3: {		// ºÏ
		if (X - 1 < 0) { return; }
		set_tmparr(tmp_arr, false);
		int tmp = tmp_arr[0];
		for (int i = 0; i < 3; i++) {
			tmp_arr[i] = tmp_arr[i + 1];
		}
		tmp_arr[3] = tmp;
		set_dice(tmp_arr, false);
		if (arr[--X][Y] != 0) {
			dice[5] = arr[X][Y];
			arr[X][Y] = 0;
		}
		else
			arr[X][Y] = dice[5];
		break;
	}
	case 4: {		// ³²
		if (X + 1 >= N) { return; }
		set_tmparr(tmp_arr, false);
		int tmp = tmp_arr[3];
		for (int i = 3; i > 0; i--) {
			tmp_arr[i] = tmp_arr[i - 1];
		}
		tmp_arr[0] = tmp;
		set_dice(tmp_arr, false);
		if (arr[++X][Y] != 0) {
			dice[5] = arr[X][Y];
			arr[X][Y] = 0;
		}
		else
			arr[X][Y] = dice[5];
		break;
	}
	}
	cout << dice[0] << endl;
}

int main() {
	cin >> N >> M >> X >> Y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int order;
		cin >> order;
		move(order);
	}
	return 0;
}