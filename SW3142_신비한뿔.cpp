#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M, U, T;		// U:������, T:Ʈ��ȥ
		cin >> N >> M;				// N:���Ǽ�, M:������

		T = N / 2;
		U = N % 2;

		while ((T + U) != M) {
			T--;
			U += 2;
		}
		cout << "# " << test_case << U << " " << T << endl;
	}

	return 0;
}