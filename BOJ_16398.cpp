#include <bits/stdc++.h>
#define MAX 2147483647
#define MIN -2147483,648
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
vector<pi2> v;
int parent[1001];
bool is_inside(int x, int y)
{
	if (x >= N || x < 0 || y < 0 || y >= M)return false;
	return true;
}
int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}
bool uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
	{
		parent[y] = x;
		return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	int N;
	cin >> N;
	int a, b;
	for (i = 1; i <= N; i++)
		parent[i] = i;
	for (i = 1; i <=N; i++)
	{
		for (j = 1; j <=N; j++)
		{
			cin >> num;
			if (num)
			{
				v.push_back({ num,{i,j} });
			}
		}
	}
	sort(v.begin(), v.end());
	for (auto a : v)
	{
		if (uni(a.second.first, a.second.second))
		{
			res += a.first;
		}
	}
	cout << res;
}
