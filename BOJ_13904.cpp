#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>pi2;
int N, M;
int num;
int i, j;
vector<pi>v;
int day[1001];
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> N;
	int a, b;
	for (i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end(),greater<pi>());
	int res = 0;
	for (i = 0; i < N; i++)
	{
		int cost = v[i].first;
		int last_day = v[i].second;
		for (j = last_day; j > 0; j--)
		{
			if (!day[j])
			{
				day[j] = 1;
				res += cost;
				break;
			}
		}
	}
	cout << res;
}
