#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <set>
using namespace std;
int N, M;
int parent[1000001];
int find(int x)
{
	if (x == parent[x])
		return x;
	else
	{
		int y = find(parent[x]);
		parent[x] = y;
		return y;
	}
}
void uni(int x, int y)
{
	x = find(x);
	y = find(y);

	parent[y] = x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int i;
	for (i = 1; i <=N; i++)
	{
		parent[i] = i;
	}
	int A, B, C;
	for (i = 0; i < M; i++)
	{
		cin >> A >>B>>C;
		if (A == 0)
		{
			uni(B, C);
		}
		else
		{
			if (find(B) == find(C))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}

