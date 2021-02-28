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
int res = 0;
int T;
int K;
int m[101][101];
int visited[101][101];
vec v;
int dp[100001];
bool is_inside(int x,int y)
{
	if (x >= N || x < 0 || y < 0 || y >= M)return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> dp[i];
	res = MIN;
	for (i = 0; i < N; i++)
	{
		dp[i] = max(dp[i], dp[i - 1] + dp[i]);
		res = max(res, dp[i]);
	}
	cout << res;

}
