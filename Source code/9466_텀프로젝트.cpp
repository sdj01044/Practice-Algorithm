#include <iostream>
#include <cstring>
using namespace std;

#define MAX_STUDENT 100001

int cnt;					// cycle에 속하는 정점 개수
int arr[MAX_STUDENT];		// i는 arr[i]를 선택
bool visited[MAX_STUDENT];	// 방문 여부
bool finished[MAX_STUDENT];	// 현재 노드의 방문함수가 끝났는지 여부

void dfs(int N, int i) {
	visited[i] = true;
	
	int next_i = arr[i];
	if (visited[next_i]) {
		if (!finished[next_i]) {	// cycle이 만들어짐
			for (int tmp = next_i; tmp != i; tmp = arr[tmp])
				cnt++;	
			cnt++;	// 자기자신
		}
	}
	else {
		dfs(N, next_i);
	}
	finished[i] = true;
}

int main() {
	int T;	cin >> T;
	for (int t = 0; t < T; t++) {
		int N;	cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		cnt = 0;
		for (int i = 1; i <= N; i++){
			if (!visited[i])
				dfs(N, i);
		}

		cout << (N - cnt) << endl;
		memset(visited, false, sizeof(visited));
		memset(finished, false, sizeof(finished));
	}//end for
	return 0;
}