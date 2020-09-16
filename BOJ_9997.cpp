#include <iostream>
#include <cstring>
using namespace std;
int N;
int chk_num;
int chk[26];
int res = 0;
void dfs(int cnt, int sum)
{
	if (cnt == N)
	{
		if (sum == chk_num)res++;
		return;
	}
	if (cnt <=N)
	{
		dfs(cnt + 1, sum | chk[cnt]);
		dfs(cnt + 1, sum);
	}

}
int main(void)
{
	cin >> N;
	int i;
	string s;
	for (i = 0; i < 26; i++)
	{
		chk_num |= 1 << i;
	}
	for (i = 0; i < N; i++)
	{
		cin >> s;
		for (auto str : s)
		{
			chk[i] |= 1 << (str - 'a');
		}
	}
	dfs(0, 0);
	cout << res;
}
