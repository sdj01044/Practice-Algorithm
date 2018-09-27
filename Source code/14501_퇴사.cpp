#include <iostream>
using namespace std;

#define MAX 16
int T[MAX];
int P[MAX];
int D[MAX];		// D[N] : N일차의 이익 최대값
int SP[MAX];	// SP[N] : T[N]일 후 얻는 이익
int N, ans = 0;

int comp_MAX(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int dp(int n) {
	for (int i = 1; i <= N; i++) {
		if (T[i] == 1)
			D[i] = comp_MAX(D[i-1] + P[i], SP[i]);
		else {
			if (i + T[i] - 1 < 16) {
				if (SP[i + T[i] - 1] < D[i - 1] + P[i])
					SP[i + T[i] - 1] = D[i - 1] + P[i];
			}
			D[i] = comp_MAX(D[i - 1], SP[i]);
		}
	}
	return D[n];
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];	// 시간, 이익
	}
	cout << dp(N) << endl;
	return 0;
}

/*#include "stdafx.h"
#include<iostream>
#include<string.h>
#include<queue>

using namespace std;
int dp[16];
int T[16];
int P[16];
int SP[16];

int Max_num(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int main()
{
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}

	dp[0] = 0;

	for (int i = 0; i <= N; i++)
	{
		SP[i] = 0;
	}

	for (int i = 1; i <= N; i++)
	{
		if (T[i] == 1)
		{
			dp[i] = Max_num(dp[i - 1] + P[i], SP[i]);
		}
		else
		{
			if (i + T[i] - 1 < 16)
			{
				if (SP[i + T[i] - 1]<dp[i - 1] + P[i])
					SP[i + T[i] - 1] = dp[i - 1] + P[i];
			}
			dp[i] = Max_num(dp[i - 1], SP[i]);
		}
	}
	cout << dp[N] << endl;
	return 0;
}*/