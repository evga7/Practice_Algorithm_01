#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>pi2;
int N, M,L;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int res = 0;
vector<int>v;
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);	cout.tie(NULL);
	cin >> N >> M >> L;
	int i;
	int num;
	v.push_back(0);
	for (i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	v.push_back(L);
	sort(v.begin(), v.end());
	int left = 1;
	int right = L-1;
	while (left <= right)
	{
		int mid = left + right >> 1;
		int cnt = 0;
		for (i =1; i < v.size(); i++)
		{
			int dist = v[i] - v[i - 1];
			if (dist> mid)
			{
				cnt += (dist-1)/ mid;
			}

		}
		if (cnt > M)
			left = mid + 1;
		else
			right = mid - 1;
	}
	cout << left;


}