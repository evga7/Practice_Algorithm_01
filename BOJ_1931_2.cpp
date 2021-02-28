#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef vector<vector<int>> vpi;
typedef vector<int> vec;
typedef vector<pi> vec2;
typedef queue<pi> que;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int num;
ll res;
int K;
vec2 v;
bool is_inside(int x, int y)
{
	if (x >= N || x < 0 || y < 0 || y >= M)return false;
	return true;
}
bool cmp(pi& p1, pi& p2)
{
	if (p1.second == p2.second)return p1.first < p2.first;
	return p1.second < p2.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> N;
	int a, b;
	for (i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(),cmp);
	ll pos = 0;
	for (i = 0; i < N; i++)
	{
		if (pos <= v[i].first)
		{
			pos = v[i].second;
			res++;
		}
	}
	cout << res;
}
