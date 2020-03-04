#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int F, G, S, U, D;
int res = 2100000000;
int visited[1000001];
queue<pair<int, int>> q;
void sol()
{
	while (!q.empty())
	{
		int s = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (s == G)
			res = min(res, cnt);
		if (s + U <= F)
		{
			if (!visited[s + U])
			{
				visited[s + U] = 1;
				q.push(make_pair(s + U, cnt + 1));
			}
		}
		if (s - D > 0)
		{
			if (!visited[s - D])
			{
				visited[s - D] = 1;
				q.push(make_pair(s - D, cnt + 1));
			}
		}
	}
}
int main()
{
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	visited[S] = 1;
	q.push(make_pair(S, 0));
	sol();
	if (res == 2100000000)
		printf("use the stairs");
	else
		cout << res;
}


