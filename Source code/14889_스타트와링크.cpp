#include <iostream>
using namespace std;

#define MAX 21
int arr[MAX][MAX];
bool visited[MAX];		// 방문한 노드 체크X, 어떤팀에 속하는지 체크 용도
int start[MAX], link[MAX];		// 두 종류의 팀
int N, ans = MAX*MAX;

void cal_ability() {			
	int s_idx = 1, l_idx = 1;
	for (int i = 1; i <= N; i++) {
		if (visited[i])			// visited = true이면 start팀
			start[s_idx++] = i;
		else                    // visited = false이면 link팀
			link[l_idx++] = i;
	}

	int s_sum = 0, l_sum = 0;
	for (int i = 1; i <= N/2; i++) {	// 팀 나눈 것중에 2명씩 골라서 능력치 더하기
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

void dfs(int v, int depth) {	// 두 팀으로 나누기위해 우선 start팀만 표시(조합원리)
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