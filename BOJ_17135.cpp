#include <iostream>
#include <queue>
using namespace std;
vector<pair<int, int>> q;
vector<pair<int, int>>q2;
vector<pair<int, int>>a;
int visited[16];
int N, M, D;
int tar_cnt = 0;
int res = 0;
int cal_distance(int r1, int c1, int r2, int c2)
{
	return abs(r1 - r2) + abs(c1 - c2);
}
void BFS(int tar_cnt)
{
	int cnt = 0;
	while (1)
	{
		if (tar_cnt <= 0)
			break;
		int i, j;
		vector<int> target;
		for (i = 0; i < 3; i++)
		{
			int index = -1;
			int cur_x = a[i].first;
			int cur_y = a[i].second;
			int Min = 9999;
			for (j = 0; j < q.size(); j++)
			{
				if (q[j].second == -1)
					continue;

				if (Min >= cal_distance(cur_x, cur_y, q[j].first, q[j].second) && D >= cal_distance(cur_x, cur_y, q[j].first, q[j].second))
				{
					if (Min == cal_distance(cur_x, cur_y, q[j].first, q[j].second) && index != -1)
					{
						if (q[index].second > q[j].second)
						{
							Min = cal_distance(cur_x, cur_y, q[j].first, q[j].second);
							index = j;
						}
						//else if (q[index].first == q[j].first)
						//{
						//	Min = cal_distance(cur_x, cur_y, q[j].first, q[j].second);
						//	index = q[index].second < q[j].second ? index : j;
						//}
					}
					else
					{
						Min = cal_distance(cur_x, cur_y, q[j].first, q[j].second);
						index = j;
					}
				}
			}
			if (index != -1)
				target.push_back(index);
		}
		for (j = 0; j < target.size(); j++)
		{
			int pos = target[j];
			if (q[pos].second == -1)
				continue;
			if (q[pos].second != -1)
			{
				q[pos].second = -1;
				tar_cnt--;
				cnt++;
			}
		}
		for (j = 0; j < q.size(); j++)
		{
			if (q[j].second == -1)
				continue;
			q[j].first++;
			if (q[j].first == N)
			{
				q[j].second = -1;
				tar_cnt--;
			}
		}
	}
	res = max(res, cnt);
}
void DFS(int cnt, int idx)
{
	if (cnt == 3)
	{
		q.clear();
		q.assign(q2.begin(), q2.end());
		BFS(tar_cnt);
	}
	else
	{
		int i;
		for (i = idx; i < M; i++)
		{
			if (visited[i])
				continue;
			visited[i] = 1;
			a.push_back(make_pair(N, i));
			DFS(cnt + 1, i);
			visited[i] = 0;
			a.pop_back();
		}
	}
}
int main()
{
	int i, j;
    int num;
	scanf("%d %d %d", &N, &M, &D);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			scanf("%d", &num);
			if (num == 1)
			{
				q2.push_back(make_pair(i, j));
				tar_cnt++;
			}
		}
	}
	DFS(0, 0);
	printf("%d", res);
}

