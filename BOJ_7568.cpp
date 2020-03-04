#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string.h>
#include <queue>
using namespace std;
int N;
vector<pair<int, int>> v;
int cnt[1000001];
int main()
{
	int i,j;
	scanf("%d", &N);
	int a, b;
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a, b));
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				cnt[i]++;
		}
	}
	for (i = 0; i < v.size(); i++)
		printf("%d ", cnt[i]+1);
}


