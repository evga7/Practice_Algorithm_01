#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int dp[501];
vector<pair<int,int>>v;
int res = 0;
int main()
{
	int N;
	scanf("%d", &N);
	int i,j;
	int a, b;
	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	int min;
	for (i = 0; i < N; i++)
	{
		min = 0;
		for (j = 0; j < i; j++)
		{
			if (v[i].second > v[j].second&&min < dp[j])
			{
				min = dp[j];
			}
		}
		dp[i] = min + 1;
		res = max(res, dp[i]);
	}
	printf("%d", N - res);


}