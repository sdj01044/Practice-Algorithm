#include <iostream>
using namespace std;

int main()
{
	int C;
	cin >> C;
	while (C--) {
		int N, L, arr[1000];
		cin >> N >> L;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		double min_price = 200.0;
		for (int day = L; day <= N; day++) {
			for (int start_day = 0; start_day <= N - day; start_day++) {
				int sum_price = 0;
				int tmp_day = day, idx = start_day;
				for (; tmp_day > 0; tmp_day--) {
					sum_price += arr[idx];
					idx++;
				}
				double avg_price = (double)sum_price / day;
				if (min_price > avg_price)
					min_price = avg_price;
			}
		}
		printf("%.10f\n",min_price);
	}
	return 0;
}