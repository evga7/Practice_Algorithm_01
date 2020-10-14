#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
int N,M;
int i, j;
vector<pi>v;
int main()
{
	cin >> N >> M;
	int a, b;
	for (i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	int idx = 0;
	int res = 0;
	for (i = 0; i < v.size(); i++)
	{
		if (v[i].second <= idx)
			continue;
		idx = max(idx, v[i].first);
		int cnt = (v[i].second - (idx + 1)) / M+1;
		res += cnt;
		idx += M * cnt;
	}
	cout << res;
}