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
int prime[4000001];
vec v;
void e()
{
	int i, j;
	for (i = 2; i <= sqrt(N); i++)
	{
		if (!prime[i])
		{
			for (j = i * i; j <= N; j += i)
			{
				prime[j] = 1;
			}
		}
	}
}
void solve()
{
	int i;
	int left = 0;
	int right = 0;
	int sum = 0;
	while (1)
	{
		if (sum >= N) {
			sum -= v[left++];
		}
		else {
			if (right + 1 > v.size())break;
			sum += v[right++];
		}
		if (sum == N)res++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	e();
	int i;
	for (i = 2; i <= N; i++)
	{
		if (!prime[i])
		{
			v.push_back(i);
		}
	}
	solve();
	cout << res;
}