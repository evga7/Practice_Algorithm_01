#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
int N, M;
int num;
int i, j;
vector<int>v;
vector<int>sub;
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> N>>M;
	int res = 0;
	if (N <= M)
	{
		cout << 0;
		return 0;
	}
	for (i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (i = 0; i < N-1; i++)
	{
		sub.push_back(v[i + 1] - v[i]);
	}
	sort(sub.begin(), sub.end());
	for (i = 0; i < N - M; i++)
		res += sub[i];
	cout << res;
}