#include <bits/stdc++.h>
#define MAX 987654321
#define MIN -987654321
using namespace std;
typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<int, string> pi3;
typedef pair<int, pair<int, int>>pi2;
typedef pair<int, char> pi4;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, M;
int num;
int res = 0;
int D, K, C;
int flag;
vector<int>v;
vector<int>v2;
int gcd(int a, int b)
{
	int temp;
	while (b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	M = MAX;
	for (i = 1; i < v.size(); i++)
	{
		v2.push_back(v[i] - v[i - 1]);
	}
	for (i=1;i<v2.size();i++)
	{
		M = min(gcd(v2[i-1],v2[i]),M);
	}
	for (i = 1; i < v.size(); i++)
	{
		int sub = v[i] - v[i - 1]-M;
			res += sub / M;
	}
	cout << res;
}