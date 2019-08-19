#include <iostream>
#include <math.h>
#include <queue>
#include <string.h>
using namespace std;
int N, K;
int dx[3] = { -1,1,2 };
int map[100001];
queue <int>q;
int BFS()
{
	while (!q.empty())
	{
		int cur_x = q.front();
		q.pop();
		if (cur_x == K)
			return map[cur_x] - 1;
		int i;
		int n_x;
		for (i = 0; i < 3; i++)
		{
			if (i < 2)
				n_x = cur_x + dx[i];
			else
				n_x = cur_x * dx[i];
			if (n_x>100000||n_x<0||map[n_x] >= 1)
				continue;
			q.push(n_x);
			map[n_x] = map[cur_x] + 1;
			if (n_x == K)
				return map[n_x] - 1;
		}
	}
}
int main()
{
	scanf("%d %d", &N, &K);
	q.push(N);
	map[N] = 1;
	printf("%d", BFS());
}