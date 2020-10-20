#include <bits/stdc++.h>
#define MAX 1000000001
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, pair<int, int>>pi2;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int res = 0;
int N;
vector<int>v;
int main()
{
	ios::sync_with_stdio(false), cin.tie(NULL);	cout.tie(NULL);
	cin >> N;
	int i;
	int num;
	v.push_back(-1);
	for (i = 0; i < N; i++)
	{
		cin >> num;
		if (v.back() < num)
		{
			v.push_back(num);
		}
		else
		{
			auto it = lower_bound(v.begin(), v.end(), num);
			*it = num;
		}
	}
	cout << v.size() - 1;
}