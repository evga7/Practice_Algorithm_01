#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>pi2;
int N, C, M;
int num;
int i, j;
vector<pi2>v;
int t[2001];
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);
	int a, b, c;
	cin >> N >> C >> M;
	for (i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		v.push_back({ b,{a,c} });
	}
	sort(v.begin(), v.end());
	ll res = 0;
	int box = 0;
	for (i = 0; i < M; i++)
	{
		box = 0;
		int from = v[i].second.first;
		int to = v[i].first;
		int cost = v[i].second.second;

		for (j = from; j < to; j++)
		{
			box = max(box, t[j]);
		}
		box = min(C - box, cost);
		res += box;
		for (j = from; j < to; j++)
			t[j] += box;
	}
	cout << res;
}





