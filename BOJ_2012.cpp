#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
int N,M;
int i, j;
vector<int>v;
int main()
{
	cin >> N;
	int num;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	ll res = 0;
	for (i = 0; i < N; i++)
	{
		res += abs((i + 1) - v[i]);
	}
	cout << res;
}