#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string str;
int k, ans;

void go(string &m, int pos, int cnt)
{
	if (cnt == k)
	{
		int ret = stoi(m);
		if (ret > ans)
		{
			ans = ret;
		}
		return;
	}

	if (pos == m.size() - 2)
	{
		string tmp = m;
		swap(tmp[pos + 1], tmp[pos]);
		go(tmp, pos, cnt + 1);
		return;
	}


	int big = -1;
	for (int i = pos; i < m.size(); i++)
	{
		if (m[i] - '0' > big)
		{
			big = m[i] - '0';
		}
	}

	if (m[pos] - '0' == big)
	{
		go(m, pos + 1, cnt);
	}

	for (int i = pos + 1; i < m.size(); i++)
	{
		if (m[i] - '0' == big)
		{
			string tmp = m;
			swap(tmp[i], tmp[pos]);
			go(tmp, pos + 1, cnt + 1);
		}
	}

}
int main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		str = "";
		k = 0, ans = 0;
		cin >> str >> k;

		go(str, 0, 0);

		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}
