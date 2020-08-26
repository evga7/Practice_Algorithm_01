#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int N, M;
int parent[200001];
int fri[200001];
int find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}
int uni(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
	{
		parent[y] = x;
		fri[x] += fri[y];
		fri[y] = 1;
	}
	return fri[x];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N ;
	int i;
	while (N--)
	{
		cin >> M;
		for (i = 1; i <= M * 2; i++)
		{
			fri[i] = 1;
			parent[i] = i;
		}
		unordered_map<string, int>h;
		int idx = 1;
		for (i = 0; i < M; i++)
		{
			string a, b;
			cin >> a >> b;

			if (h.find(a) == h.end())
			{
				h.insert(make_pair(a, idx++));
			}
			if (h.find(b) == h.end())
			{
				h.insert(make_pair(b, idx++));
			}

			int x = h[a];
			int y = h[b];
			cout<<uni(x, y)<<"\n";
		}
	}
}