#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
int N,M;
#define MAX 2147483647
vector<int>v;
int res = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	int i;
	int num;
	for (i = 0; i < M;i++)
	{
		cin >> num;
		v.push_back(num);
	}
	int j, k;
	for (i = 1; i < M-1; i++)
	{
		int l, r;
		l = r = v[i];
		for (j = 0; j < i; j++)
			l = max(l, v[j]);
		for (j = i+1 ; j < M; j++)
			r = max(r, v[j]);
		res += min(l, r) - v[i];
	}
	cout << res;
}

