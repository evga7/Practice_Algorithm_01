#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;
int parent[1001];
int N, M;
vector<pair<pair<int, int>,int>> v;
int res = 0;
bool cmp(pair<pair<int, int>, int> &v1, pair<pair<int, int>, int> &v2)
{
	return v1.second < v2.second;
}
int find_parent(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find_parent(parent[x]);
}
bool same_parent(int x, int y)
{
	x = find_parent(x);
	y = find_parent(y);
	if (x == y)
	{
		return true;
	}
	else
		return false;
}

void uni(int x, int y)
{
	x = find_parent(x);
	y = find_parent(y);
	if (x != y)
	{
		parent[y] = x;
	}
}
int main()
{
	cin >> N >> M;
	int i;
	int a,b,c;
	for (i = 1; i <= N; i++)
		parent[i] = i;
	for (i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		v.push_back(make_pair(make_pair(a, b),c));
	}
	sort(v.begin(), v.end(),cmp);
	for (i = 0; i < M; i++)
	{
		if (!same_parent(v[i].first.first, v[i].first.second))
		{
			uni(v[i].first.first, v[i].first.second);
			res += v[i].second;
		}
	}
	cout << res;
}