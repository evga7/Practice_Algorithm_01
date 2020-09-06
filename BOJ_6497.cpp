#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>
#define MAX 987654321
using namespace std;
typedef pair<int, int>pi;
vector<pair<int,pi>> graph;
int parent[200001];
int N, M;
long long res = 0;
long long sum = 0;
int find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x]=find(parent[x]);
}
void uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		parent[y] = x;
}
bool chk (int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return true;
	else
		return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i;
	int a, b, c;
	while (1)
	{
		cin >> N >> M;
		graph.clear();
		if (!N && !M)
		{
			break;
		}
		for (i = 0; i < M; i++)
		{
			cin >> a >> b >> c;
			graph.push_back(make_pair(c, make_pair(a, b)));
			graph.push_back(make_pair(c, make_pair(b, a)));
			sum += c;
		}
		cin >> a >> b;
		for (i = 0; i < N; i++)
			parent[i] = i;
		sort(graph.begin(), graph.end());
		for (i = 0; i < graph.size(); i++)
		{
			a = graph[i].second.first;
			b = graph[i].second.second;
			c = graph[i].first;
			if (!chk(a, b))
			{
				uni(a, b);
				res += c;
			}
		}
		cout << sum - res;
	}
}

