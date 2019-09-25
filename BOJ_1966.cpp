#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;

int main()
{
	int T, N, M;
	int i,j;
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		priority_queue<int>pq;
		queue < pair<int, int>>q;
		scanf("%d %d", &N, &M);
		for (j = 0; j < N; j++)
		{
			int num;
			scanf("%d", &num);
			q.push(make_pair(num,j));
			pq.push(num);
		}
		int cnt = 0;
		while (!q.empty())
		{
			int num, idx;
			num = q.front().first;
			idx = q.front().second;
			if (num== pq.top())
			{
				cnt++;
				pq.pop();
				if (M == idx)
				{
					printf("%d\n", cnt);
					break;
				}
			}
			q.pop();
			q.push(make_pair(num, idx));
		}
	}

}
