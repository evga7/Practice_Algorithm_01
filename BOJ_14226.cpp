#include <iostream>
#include <math.h>
#include <queue>
#include <string.h>
#include <cmath>
#include <string>
using namespace std;
int res = 2100000000;
int S;
int visited[2001][2001];
queue<pair<pair<int, int>,int>> q;
void BFS()
{
	q.push(make_pair(make_pair(0, 1),0));
	while (!q.empty())
	{
		int cur_cnt = q.front().first.first;
		int cur_sum = q.front().first.second;
		int cur_copy = q.front().second;
		if (cur_sum==S)
		res = min(res, cur_cnt);
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			int n_cnt, n_sum,n_copy;
			if (i == 0)
			{
				n_cnt = cur_cnt + 1;
				n_sum = cur_sum;
				n_copy = cur_sum;
			}
			else if (i == 1)
			{
				n_cnt = cur_cnt + 1;
				n_sum = cur_sum + cur_copy;
				n_copy = cur_copy;
			}
			else
			{
				n_cnt = cur_cnt + 1;
				n_sum = cur_sum-1;
				n_copy = cur_copy;
			}
			if (cur_cnt > res || n_sum > S||visited[n_sum][n_copy])
				continue;
			q.push(make_pair(make_pair(n_cnt, n_sum), n_copy));
			visited[n_sum][n_copy] = 1;
		}
	}
}

int main()
{
	scanf("%d", &S);
	BFS();
	printf("%d", res);
}