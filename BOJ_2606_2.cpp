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
int parent[101];
int find(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}
void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
	{
		parent[y] = x;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int i;
	int a, b;
	for (i = 1; i <= N; i++)
		parent[i] = i;
	for (i = 0; i < M; i++)
	{
		cin >> a >> b;
		uni(a, b);
	}
	int root = find(1);
	for (i = 2; i <= N; i++)
		if (find(i) == root)
			res++;
	cout << res;
}