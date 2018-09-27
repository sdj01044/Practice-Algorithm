#include <iostream>
using namespace std;

#define MAX 21
int arr[MAX][MAX];
bool visited[MAX];		// �湮�� ��� üũX, ����� ���ϴ��� üũ �뵵
int start[MAX], link[MAX];		// �� ������ ��
int N, ans = MAX*MAX;

void cal_ability() {			
	int s_idx = 1, l_idx = 1;
	for (int i = 1; i <= N; i++) {
		if (visited[i])			// visited = true�̸� start��
			start[s_idx++] = i;
		else                    // visited = false�̸� link��
			link[l_idx++] = i;
	}

	int s_sum = 0, l_sum = 0;
	for (int i = 1; i <= N/2; i++) {	// �� ���� ���߿� 2�� ��� �ɷ�ġ ���ϱ�
		for (int j = i + 1; j <= N/2; j++) {
			s_sum += arr[start[i]][start[j]];
			s_sum += arr[start[j]][start[i]];

			l_sum += arr[link[i]][link[j]];
			l_sum += arr[link[j]][link[i]];
		}
	}
	int diff = abs(s_sum - l_sum);
	if (ans > diff)
		ans = diff;
}

void dfs(int v, int depth) {	// �� ������ ���������� �켱 start���� ǥ��(���տ���)
	if (depth == N/2) {
		visited[v] = true;
		cal_ability();
		visited[v] = false;
		return;
	}

	visited[v] = true;
	for (int i = v + 1; i <= N; i++) {
		dfs(i, depth + 1);
	}
	visited[v] = false;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(1, 1);
	cout << ans << endl;
	return 0;
}