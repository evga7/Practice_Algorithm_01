#include <bits/stdc++.h>
#include <unordered_map>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int N, M;
int num;
int res;
string dp[101][101];
string cal(string s1,string s2)
{
	ll sum = 0;
	string res;
	while (!s1.empty() || !s2.empty() || sum)
	{
		if (!s1.empty())
		{
			sum += s1.back() - '0';
			s1.pop_back();
		}
		if (!s2.empty())
		{
			sum += s2.back() - '0';
			s2.pop_back();
		}
		res.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(res.begin(), res.end());
	return res;	
}
string solve(int n, int r)
{
	if (n == r || r == 0)
		return "1";
	string& ret = dp[n][r];
	if (!ret.empty())
		return ret;
	return ret = cal(solve(n - 1, r - 1),solve(n - 1, r));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	cout<<solve(N,M);
}