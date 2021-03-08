#include <bits/stdc++.h>
#define MAX 2147483647
#define MIN -2147483648
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef vector<vector<int>> vpi;
typedef vector<int> vec;
typedef vector<pi> vec2;
typedef queue<pi> que;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int res;
int num;
int reco[101];
int times[101];
vec v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cout.tie(0);
	int i, j;
	cin >> N >> M;
	for (i = 0; i < M; i++)
	{
		cin >> num;
		int flag = 0;
		if (reco[num])flag = 1;
		reco[num]++;
		for (j = 1; j <= 100; j++)
		{
			if (reco[j])times[j]++;
		}
		if (v.size() >= N && !flag)
		{
			int m = reco[v[0]];
			int idx = 0;
			for (j = 0; j < v.size(); j++)
			{
				if (m > reco[v[j]])
				{
					m = reco[v[j]];
					idx = j;
				}
			}
			for (j = 0; j < v.size(); j++)
			{
				if (m == reco[v[j]] && idx != j)
				{
					if (times[v[idx]] < times[v[j]])
					{
						idx = j;
					}
				}
			}
			times[v[idx]] = 0;
			reco[v[idx]] = 0;
			v.erase(v.begin() + idx);
			flag=0;
		}
		if(!flag)
			v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (auto a : v)cout << a << " ";
}



