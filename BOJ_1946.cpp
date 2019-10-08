#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	int N;
	scanf("%d", &T);
	while (T--)
	{
		cin >> N;
		int i, j;
		int res = 1;
		vector<pair<int, int>>v;
		for (i = 0; i < N; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end());
		int Max= v.front().second;
		for (i = 1; i < N; i++)
		{
			if (Max > v[i].second)
			{
				Max = v[i].second;
				res++;
			}
		}
		printf("%d\n", res);
	}
}
