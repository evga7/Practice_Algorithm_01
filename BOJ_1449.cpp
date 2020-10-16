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
vector<int>v;
int chk[10001];
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> N >> M;
	int cnt = 0;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (i = 0; i < N; i++)
	{
		int num = v[i];
		if (!chk[num])
		{
			for (j = num; j < num + M; j++)
			{
				chk[j] = 1;

			}
			cnt++;
		}
	}
	cout << cnt;
}


