#include <iostream>
#include <math.h>
#include <queue>
#include <string.h>
using namespace std;
int N, K;
int dx[3] = { -1,1,2 };
int map[100001];
queue <int>q;
int res = 999999;
int cnt = 0;
void BFS()
{
	while (!q.empty())
	{
		int cur_x = q.front();
		q.pop();
		if (cur_x == K)
		{
			cnt++;
			res = min(res, map[cur_x] - 1);
		}
		int i;
		int n_x;
		for (i = 0; i < 3; i++)
		{
			if (i < 2)
				n_x = cur_x + dx[i];
			else
				n_x = cur_x * dx[i];
			if (n_x>100000||n_x<0)
				continue;
			if (map[n_x] && map[cur_x]+1 > map[n_x])
				continue;
			q.push(n_x);
			map[n_x] = map[cur_x] + 1;
		}
	}
}
int main()
{
	scanf("%d %d", &N, &K);
	q.push(N);
	map[N] = 1;
	BFS();
	printf("%d\n%d",res, cnt);
}