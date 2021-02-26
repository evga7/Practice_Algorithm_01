#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef pair<int, char> pi4;
typedef vector<vector<int>> vpi;
typedef vector<int> vec;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int num;
int res;
int res2;
int dp[41];
int T;
int solve(int n)
{
	int& ret = dp[n];
	if (ret) return ret;
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		dp[1] = 1;
		return 1;
	}

	return ret = solve(n - 1) + solve(n - 2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		solve(N);
		if (N == 0)
			cout << 1 << " " << 0 << "\n";
		else if (N == 1)
			cout << 0 << " " << 1 << "\n";
		else
			cout << dp[N - 1] << " " << dp[N] << "\n";;
	}

}
