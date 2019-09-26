#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
int visited[201][201];
int dx[6] = { -2,-2,0,0,2,2 };
int dy[6] = { -1,1,-2,2,-1,1 };
int res = 999999999;
int N;
int r1, c1, r2, c2;
queue<pair<pair<int, int>,int>>q;
void BFS()
{
	while (!q.empty())
	{
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if ((cur_x==r2)&&(cur_y==c2))
		{
			res = min(res, cnt);
		}
		int i;
		for (i = 0; i < 6; i++)
		{
			int n_x = cur_x + dx[i];
			int n_y = cur_y + dy[i];
			if (n_x < 0 || n_x >= N|| n_y < 0 || n_y >=N || visited[n_x][n_y])
				continue;
			q.push(make_pair(make_pair(n_x, n_y),cnt+1));
			visited[n_x][n_y] = 1;
		}
	}
}
int main()
{
	scanf("%d", &N);
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	q.push(make_pair(make_pair(r1, c1), 0));
	BFS();
	if (res!= 999999999)
		printf("%d", res);
	else
		printf("-1");
}