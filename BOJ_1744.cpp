#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
int N, M;
ll num;
int i, j;
vector<ll>v;
vector<ll>p;
vector<ll>m;
int chk[10001];
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int len = v.size();
	for (i = 0; i < len; i++)
	{
		if (v[i] > 0)
			p.push_back(v[i]);
		else
			m.push_back(v[i]);
	}
	ll res = 0;
	len = p.size();
	for (i = len-1; i >=0; i--)
	{
		if (!chk[i])
		{
			if (i - 1 >=0 && p[i] * p[i - 1] > 1 && !chk[i] && !chk[i - 1]&&p[i]+p[i-1]<p[i]*p[i-1])
			{
				if (!res)
					res = p[i] * p[i - 1];
				else
					res += p[i] * p[i - 1];
				chk[i] = chk[i - 1] = 1;
			}
			else
				res += p[i];
		}
	}
	fill(chk, chk + N + 1, 0);
	len = m.size();
	for (i = 0; i < len; i++)
	{
		if (!chk[i])
		{
			if (i +1 < len && m[i] * m[i + 1] >=0 && !chk[i] && !chk[i + 1])
			{
				if (!res)
					res = m[i] * m[i + 1];
				else
					res += m[i] * m[i + 1];
				chk[i] = chk[i + 1] = 1;
			}
			else
				res += m[i];
		}
	}
	cout << res;
}