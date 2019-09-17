#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N,M;
int arr[51][51];
int res = 99999999;
int visited[101];
vector<pair<int, int>>v;
vector<pair<int, int>> v2;
vector<pair<int, int>> v3;

void DFS(int cnt,int idx)
{
	if (cnt == M)
	{
		int cnt = 9999999;
		int sum = 0;
		for (auto house : v)
		{
			cnt = 999999;
			for (auto num : v3)
			{
				cnt = min(abs(house.first - num.first) + abs(house.second - num.second),cnt);
			}
			sum += cnt;
		}
		res = min(sum, res);
		return;
	}
		int i;
		for (i = idx; i < v2.size(); i++)
		{
			if (!visited[i])
			{
				visited[i] = 1;
				v3.push_back(make_pair(v2[i].first, v2[i].second));
				DFS(cnt + 1,i+1);
				visited[i] = 0;
				v3.pop_back();
				
			}
		}
}
int main()
{
	int i, j, k;
	scanf("%d %d", &N,&M);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
				v.push_back(make_pair(i, j));
			if (arr[i][j] == 2)
				v2.push_back(make_pair(i, j));
		}
	}
	DFS(0, 0);
	printf("%d", res);
}
