#include <iostream>
#include<string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int K;
vector<vector<int>>res;
int idx = 0;
void DFS(vector<int>v, int sum)
{
	if (sum == N)
	{
		res.push_back(v);
		return;
	}
	else
	{
		int i;
		for (i = 1; i <= 3; i++)
		{
			if (sum+ i<=N)
			{
				v.push_back(i);
				DFS(v, sum + i);
				v.pop_back();
			}
		}
	}
}
int main() 
{
	scanf("%d %d", &N,&K);
	vector<int>v;
	DFS(v,0);
	int i;
	if (K-1>=res.size())
		printf("-1");
	else
	{
		for (i = 0; i < res[K - 1].size(); i++)
		{
			if (i == 0)
				printf("%d", res[K - 1][i]);
			else
				printf("+%d", res[K - 1][i]);
		}
	}
}