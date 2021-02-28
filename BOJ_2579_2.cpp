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
vec v;
int dp[305];
int solve()
{
	int i;
	dp[0] = v[0];
	dp[1] = v[0] + v[1];
	dp[2] = max(v[2] + v[1], v[0] + v[2]);
	for (i = 3; i < N; i++)
	{
		dp[i] = max(dp[i-3]+v[i]+v[i-1], dp[i - 2] + v[i]);
	}
	return dp[N - 1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	cout <<solve();

}
