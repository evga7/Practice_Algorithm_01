#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 987654321
int dp[101][101][2];
string str;
string s[2];
int len;
int res = 0;
int S;
int solve(int col, int row, int idx)
{
	if (idx ==S)
		return 1;

	int& ret = dp[col][row][idx];
	if (ret != -1)
		return ret;
	int i;
	ret = 0;
	for (i = row; i < len; i++)
	{
		if (s[col][i] == str[idx])
			ret += solve(1 - col, i+1, idx + 1);
	}
	return ret;
}
int main() {
	string temp;
	cin >> str >> s[0] >> s[1];
	int i;
	len = s[0].size();
	S = str.size();
	memset(dp, -1, sizeof(dp));
	for (i = 0; i < 2; i++)
	{
		res += solve(i,0,0);
	}

	cout << res;
}