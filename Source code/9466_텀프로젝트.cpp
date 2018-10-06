#include <iostream>
#include <cstring>
using namespace std;

#define MAX_STUDENT 100001

int cnt;					// cycle�� ���ϴ� ���� ����
int arr[MAX_STUDENT];		// i�� arr[i]�� ����
bool visited[MAX_STUDENT];	// �湮 ����
bool finished[MAX_STUDENT];	// ���� ����� �湮�Լ��� �������� ����

void dfs(int N, int i) {
	visited[i] = true;
	
	int next_i = arr[i];
	if (visited[next_i]) {
		if (!finished[next_i]) {	// cycle�� �������
			for (int tmp = next_i; tmp != i; tmp = arr[tmp])
				cnt++;	
			cnt++;	// �ڱ��ڽ�
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